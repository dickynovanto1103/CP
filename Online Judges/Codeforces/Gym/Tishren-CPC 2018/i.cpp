#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll MOD = 1e9 + 7;

ll mod(long long n) {
    return ((n % MOD) + MOD) % MOD;
}

ll add(long long a, long long b) {
    return mod(a + b);
}

ll sub(long long a, long long b) {
    return mod(a - b);
}

ll mult(long long a, long long b) {
    if (b == 0) return 0;
    ll m = mult(a, b / 2);
    ll mm = add(m, m);
    return add(mm, (b & 1 ? a : 0));
}

ll power(long long a, long long b) {
    if (b == 0) return 1;
    ll p = power(a, b / 2);
    ll pp = mult(p, p);
    return mult(pp, (b & 1 ? a : 1));
}

const int maxn = 1e5 + 5;

int main() {
    int t;
    scanf("%d", &t);
    int a[maxn], odd[maxn];

    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        odd[0] = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            odd[i + 1] = (a[i] & 1) + odd[i];
        }

        for (int i = 0; i < q; i++) {
            int l, r, t;
            scanf("%d %d %d", &l, &r, &t);

            ll odds = sub(power(2LL, (ll)odd[r] - (ll)odd[l - 1]), 1);
            if (t == 1) {
                printf("%lld\n", odds);
            } else {
                ll alls = sub(power(2LL, (ll)(r - l + 1)), 1);
                printf("%lld\n", sub(alls, odds));
            }
        }
    }

    return 0;
}