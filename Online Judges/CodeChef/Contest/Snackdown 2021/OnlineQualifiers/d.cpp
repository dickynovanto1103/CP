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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(ii a, ii b) {
	return a.first > b.first;
}

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);

	vector<vi> adj;
	int ans[300010];
	while(tc--){
		scanf("%d %d",&n,&m);
		adj.assign(n+1, vi());
		for(i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].pb(b); adj[b].pb(a);
		}

		vii v;

		for(i=1;i<=n;i++){
			int numV = adj[i].size();
			v.pb(ii(numV, i));
			// printf("num neighbor of %d is: %d\n", i, numV);
		}

		sort(v.begin(), v.end(), cmp);
		for(i=0;i<v.size();i++){
			ii el = v[i];
			ans[el.second] = i+1;
		}

		int maks = 0, minim = inf;
		for(i=1;i<=n;i++){
			int cnt = 0;
			for(j=0;j<adj[i].size();j++){
				int v = adj[i][j];
				if(ans[v] < ans[i]) {
					cnt++;
				}
			}
			maks = max(maks, cnt);
			minim = min(minim, cnt);
		}
		printf("%d\n", maks-minim);
		for(i=1;i<=n;i++){
			if(i > 1){printf(" ");}
			printf("%d",ans[i]);
		}
		puts("");
	}
	
	return 0;
};