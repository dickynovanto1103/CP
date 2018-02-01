#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

int memo[101];
vi dfs_num;

int solve(int awal){
	int ukuran = AdjList[awal].size();
	dfs_num[awal] = visited;
	/*if(ukuran==0){return memo[awal] = 0;}
	if(memo[awal]!=-1){return memo[awal];}*/
	int ans = 0;
	for(int i=0;i<ukuran;i++){
		int v = AdjList[awal][i];
		if(dfs_num[v]==unvisited){
			
			int temp = solve(v);
			/*printf("examine %d\n",v);
			printf("hasil temp: %d\n",temp);*/
			ans+=(1+temp);
		}
		
	}
	
	return ans;
	
}

int main() {
	int n,m,i,j;
	while(scanf("%d",&n),n){
		AdjList.assign(n+1,vi());
		
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			int bil;
			for(j=0;j<m;j++){scanf("%d",&bil); AdjList[i].pb(bil);}
		}

		//memset(memo,-1,sizeof memo);
		int ans = -inf, idx;
		for(i=1;i<=n;i++){
			dfs_num.assign(n+1,unvisited);
			
			memo[i] = solve(i);
			/*printf("i: %d\n",i);
			printf("temp: %d\n",memo[i]);*/
			if(ans < memo[i]){idx = i; ans  = memo[i];}
			ans = max(ans,memo[i]);
		}
		//printf("ans: %d\n",ans);
		
		/*for(i=1;i<=n;i++){
			printf("memo[%d]: %d\n",i,memo[i]);
			if(memo[i]==ans){break;}
		}*/
		printf("%d\n",idx);
		AdjList.clear();
	}
	return 0;
}