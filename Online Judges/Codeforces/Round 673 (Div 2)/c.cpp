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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[300001];
	int ans[300002];
	while(tc--){
		scanf("%d",&n);
		vector<vi> adj;
		adj.assign(n+1,vi());
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			adj[a[i]].pb(i);
			ans[i+1] = inf;
		}

		int curMaks = inf;
		for(i=1;i<=n;i++){
			int curIdx = -1;
			int maksJarak = -1;
			for(j=0;j<adj[i].size();j++){
				int idx = adj[i][j];
				// printf("i: %d idx: %d\n",i, idx);
				
				maksJarak = max(maksJarak, idx - curIdx);
				
				curIdx = idx;
			}
			if(maksJarak == -1){continue;}

			maksJarak = max(maksJarak, n - curIdx);
			// printf("i: %d maksJarak: %d\n",i, maksJarak);
			if(maksJarak >= curMaks){continue;}
			ans[maksJarak] = i;
			curMaks = maksJarak;
		}
		curMaks = inf;
		for(i=1;i<=n;i++){
			if(ans[i] == inf){
				ans[i] = curMaks;
				if(ans[i] == inf){
					ans[i] = -1;
				}else{

				}
			}else{
				curMaks = ans[i];
			}
			
			if(i>1){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
};