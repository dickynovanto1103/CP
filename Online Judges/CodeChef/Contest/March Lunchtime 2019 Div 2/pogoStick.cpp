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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&k);
		int ukuran = n >= k ? k : n;
		vector<vi> adj(ukuran);
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			adj[i%k].pb(bil);
		}
		int ans = -inf;
		for(i=0;i<ukuran;i++){
			int jawab = 0;
			for(j=adj[i].size()-1; j>=0;j--){
				jawab += adj[i][j];
				ans = max(ans, jawab);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};