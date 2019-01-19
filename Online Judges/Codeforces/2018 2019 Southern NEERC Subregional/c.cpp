#include <bits/stdc++.h>
#define left first.first
#define right first.second
#define ncore second.first
#define price second.second
#define fi first
#define se second
#define mp(a, b, c, d) make_pair(make_pair(a, b), make_pair(c, d))
#define p4 pair<pair<int, int>, pair<int, int> >
#define p2 pair<int, int>
#define DEBUG if (debug)
using namespace std;

const bool debug = false;

int n, k, m;
int l, r, c, p;
vector<p4> v;
int used[200005]; // -1 = out of range, 0 = unused
                  // k = used fully, 1 to (k-1) = used partially
vector<p2> starting_point;
vector<p2> termination_point;

bool cmp(const p4& a, const p4& b) {
    if (a.left != b.left)
        return a.left < b.left;
    return a.right < b.right;
}

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i=0; i<m; i++) {
        scanf("%d%d%d%d", &l, &r, &c, &p);
        v.push_back(mp(l, r, c, p));
        starting_point.push_back(make_pair(l, i));
        termination_point.push_back(make_pair(r, i));
    }
    sort(starting_point.begin(), starting_point.end());
    sort(termination_point.begin(), termination_point.end());

    long long ans = 0LL;
    long long run = 0LL;
    int l = 0, r = 0;
    int core = 0;
    priority_queue<p2> available;
    priority_queue<p2> already_used;
    for (int day = 1; day <= n; day++) {
        DEBUG printf("day %d begin\n", day);
        for (; termination_point[l].first < day && l < m; l++) {
            int idx = termination_point[l].second;
            core -= used[idx];
            run -= (long long) used[idx] * v[idx].price;
            used[idx] = -1;
            DEBUG printf("plan(l=%d,r=%d,c=%d,p=%d) will no longer be used\n", v[idx].left, v[idx].right, v[idx].ncore, v[idx].price);
        }
        for (; starting_point[r].first <= day && r < m; r++) {
            int idx = starting_point[r].second;
            used[idx] = 0;
            DEBUG printf("plan(l=%d,r=%d,c=%d,p=%d) now can be used\n", v[idx].left, v[idx].right, v[idx].ncore, v[idx].price);

            while (!already_used.empty()) {
                p2 t = already_used.top();
                if (t.first <= v[idx].price) {
                    break;
                }
                DEBUG printf("highest price used is %d, so we drop it\n", t.first);
                int will_be_used = 0;
                if (v[idx].ncore - used[idx] <= used[t.second]) {
                    will_be_used = v[idx].ncore - used[idx];
                } else {
                    will_be_used = used[t.second];
                    already_used.pop();
                }
                if (used[t.second] == v[t.second].ncore) available.push(make_pair(-t.first, t.second));
                if (used[idx] == 0) already_used.push(make_pair(v[idx].price, idx));
                DEBUG printf("%d cores will be taken from this plan\n", will_be_used);
                DEBUG printf("%d cores will be dropped from the highest price\n", will_be_used);
                used[t.second] -= will_be_used;
                used[idx] += will_be_used;
                run -= (long long) will_be_used * t.first;
                run += (long long) will_be_used * v[idx].price;
            }
            if (used[idx] < v[idx].ncore) {
                available.push(make_pair(-v[idx].price, idx));
            }
        }

        while (core < k && !available.empty()) {
            DEBUG printf("needed %d more cores.\n", k - core);
            p2 t = available.top(); int idx = t.second;
            if (used[idx] >= 0 && used[idx] < v[idx].ncore) {
                int will_be_used = 0;
                if (v[idx].ncore - used[idx] <= k - core) {
                    will_be_used = v[idx].ncore - used[idx];
                    available.pop();
                } else {
                    will_be_used = k - core;
                }
                already_used.push(make_pair(v[idx].price, idx));
                DEBUG printf("%d cores will be taken from plan(l=%d,r=%d,c=%d,p=%d)\n", will_be_used, v[idx].left, v[idx].right, v[idx].ncore, v[idx].price);
                core += will_be_used;
                used[idx] += will_be_used;
                run += (long long) will_be_used * v[idx].price;
            } else {
                available.pop();
            }
            DEBUG { volatile int i = 0; while (i < 100000000) { i++; } }
        }
        DEBUG printf("end of day %d, we pay %lld.\n", day, run);
        ans += run;
    }
    printf("%lld\n", ans);
}