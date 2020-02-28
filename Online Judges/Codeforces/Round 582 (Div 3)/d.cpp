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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> adj;
const int maxn = 2e5 + 5;

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	adj.assign(maxn, vi());
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		adj[bil].pb(0);
		int cnt = 1;
		while(bil) {
			bil /= 2;
			adj[bil].pb(cnt++);
		}
	}
	for(i=0;i<maxn;i++){
		sort(adj[i].begin(), adj[i].end());
	}
	ll ans = inf;
	for(i=0;i<maxn;i++){
		ll sum = 0;
		int cnt = 0;
		bool valid = false;
		for(j=0;j<adj[i].size();j++){
			cnt++;
			sum += adj[i][j];
			// printf("i: %d step: %d\n",i, adj[i][j]);
			if(cnt == k){valid = true; break;}
		}
		if(valid){
			ans = min(ans, sum);
		}
		
		
	}
	printf("%lld\n",ans);
	return 0;
};