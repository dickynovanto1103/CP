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

const int maxn = 1e5 + 5;
int dp[maxn][2];

vector<vi> AdjList;
int isLeaf[maxn];

void determineLeaf(int node, int parent){
	int cnt = 0;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent){
			determineLeaf(v, node);
			cnt++;
		}
	}
	if(cnt == 0){
		isLeaf[node] = true;
	}
}

int solve(int node, int flag, int parent){
	int i;
	if(dp[node][flag] != -1){return dp[node][flag];}
	if(isLeaf[node]){
		return dp[node][flag] = flag;
	}
	int ans;
	// printf("node: %d flag: %d parent: %d\n", );
	if(flag == 0){
		//antara dia tetangganya diwarnai atau ngga
		ans = 0;
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			if(v!=parent){
				ans += solve(v, 1, node);	
			}
			
		}
		
	}else{
		ans = 1;
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			if(v!=parent){
				ans += min(solve(v, 0, node), solve(v, 1, node));	
			}
			
		}
	}

	return dp[node][flag] = ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	int minim = inf;
	for(i=0;i<(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
		minim = min(minim, min(a,b));
	}

	memset(isLeaf, false, sizeof isLeaf);
	determineLeaf(minim, -1);
	// printf("leaf\n");
	// for(i=1;i<=n;i++){
	// 	if(isLeaf[i]){
	// 		printf("%d\n",i);
	// 	}
	// }
	// printf("\n");
	memset(dp,-1,sizeof dp);
	int ans = min(solve(minim, 0, -1), solve(minim, 1, -1));
	printf("%d\n",ans);

	return 0;
};