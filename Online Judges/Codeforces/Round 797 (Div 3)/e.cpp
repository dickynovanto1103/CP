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

vector<vi> adj;

int main(){
	int tc;
	scanf("%d",&tc);

	int a[200001];

	while(tc--){
		int n, k;
		scanf("%d %d",&n, &k);

		adj.assign(k+1, vi());
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			adj[a[i]%k].pb(a[i]);
		}

		ll ans = 0;

		for(int i=0;i<k;i++){
			int pasangan = k - i;
			pasangan %= k;
			if(pasangan == i) {
				//pasang2 in sendiri
				while(adj[i].size() >= 2){
					int bil1 = adj[i].back(); adj[i].pop_back();
					int bil2 = adj[i].back(); adj[i].pop_back();

					ans += ((bil1 + bil2) / k);
				}

			}else{
				while(adj[i].size() && adj[pasangan].size()) {
					int bil1 = adj[i].back(); adj[i].pop_back();
					int bil2 = adj[pasangan].back(); adj[pasangan].pop_back();
					ans += ((bil1 + bil2) / k);
				}
			}
		}

		vi rem;
		for(int i=0;i<k;i++){
			for(int j=0;j<adj[i].size();j++){
				int bil = adj[i][j];
				ans += (bil / k);
				bil %= k;
				rem.pb(bil);
			}
		}

		sort(rem.begin(), rem.end());

		deque<int> dq;
		for(int bil: rem) {
			dq.push_back(bil);
		}

		while(dq.size()) {
			assert(dq.size() >= 2);
			int front = dq.front(), back = dq.back();
			if((front + back) >= k) {
				ans++;
				dq.pop_front(); dq.pop_back();
			}else{
				dq.pop_front(); dq.pop_front();
			}
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
};