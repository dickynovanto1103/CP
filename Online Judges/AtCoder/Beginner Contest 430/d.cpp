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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(){
	int n;
	while(scanf("%d",&n) == 1) {
		ll sum = 2*inf;
		unordered_map<int, int> dist;
		dist[0] = 2*inf;
		set<int> s;
		set<int>::iterator it, it2;
		s.insert(0);
		
		for(int i=1;i<=n;i++) {
			int pos;
			scanf("%d",&pos);
			s.insert(pos);
			it = s.find(pos);
			it--;
			int prevPos = *it;
			
			sum -= dist[*it];
			dist[*it] = min(dist[*it], pos- *it);
			sum += dist[*it];
			// printf("PREV sum now: %lld\n", sum);
			it = s.find(pos);
			it++;
			int nextPos = -1;
			if(it != s.end()) {
				nextPos = *it;
				sum -= dist[*it];
				dist[*it] = min(dist[*it], *it - pos);
				sum += dist[*it];
				// printf("AFTER sum now: %lld\n", sum);
			}
			// printf("i: %d pos: %d prevPos: %d nextPos: %d\n", i, pos, prevPos, nextPos);

			dist[pos] = pos - prevPos;
			if(nextPos != -1) {
				dist[pos] = min(dist[pos], nextPos - pos);
			}

			sum += dist[pos];
			// printf("ON POS sum now: %lld\n", sum);
			printf("%lld\n", sum);
		}
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};