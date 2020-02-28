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

vector<vi> adj;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		adj.assign(n+1, vi());
		for(i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			adj[a].pb(i);
		}
		bool valid = false;
		int ans = inf;
		for(i=1;i<=n;i++){
			if(adj[i].size() >= 2){
				valid = true;
				for(j=0;j<adj[i].size()-1;j++){
					ans = min(ans, adj[i][j+1] - adj[i][j] + 1);
				}
			}
		}
		if(!valid){printf("-1\n");}
		else{printf("%d\n",ans);}
	}
	return 0;
};