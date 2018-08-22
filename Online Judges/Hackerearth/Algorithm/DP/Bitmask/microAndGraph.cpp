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

vector<vii> AdjList;
int n;
int dp[15][1<<11];

int solve(int idx, int bitmask){
	if(bitmask == ((1<<n) - 1)){return 0;}//all node is visited
	if(dp[idx][bitmask] != -1){return dp[idx][bitmask];}
	int i;
	int ans = inf;
	// printf("idx: %d bitmask: %d\n",idx,bitmask);
	for(i=0;i<AdjList[idx].size();i++){
		ii v = AdjList[idx][i];
		int tetangga = v.first, berat = v.second;
		// printf("tetangga: %d berat: %d\n",tetangga, berat);
		if(!((1<<tetangga) & bitmask)){
			ans = min(ans, solve(tetangga, (1<<tetangga) | bitmask) + berat);
		}
	}

	return dp[idx][bitmask] = ans;
}

int main(){
	int m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vii());
	for(i=0;i<m;i++){
		int a,b,w;
		
		scanf("%d %d %d",&a,&b,&w);
		a--; b--;
		AdjList[a].pb(ii(b,w)); AdjList[b].pb(ii(a,w));
	}

	// for(i=0;i<n;i++){
	// 	printf("node %d:",i);
	// 	for(j=0;j<AdjList[i].size();j++){
	// 		ii v = AdjList[i][j];
	// 		int node = v.first, berat = v.second;
	// 		printf(" %d(%d)",node,berat);
	// 	}
	// 	printf("\n");
	// }

	memset(dp, -1, sizeof dp);

	int ans = inf;
	for(i=0;i<n;i++){
		int jawab = solve(i, 1<<i);	
		ans = min(ans, jawab);
	}

	
	printf("%d\n",ans);

	return 0;
};