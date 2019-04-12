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

const int maxn = 1001;

int dp[maxn][maxn];

vector<vi> AdjList;
int a[maxn];
int m;
int solve(int idx, int nodeSekarang) {
	if(idx == m){return 0;}
	if(dp[idx][nodeSekarang] != -1){return dp[idx][nodeSekarang];}
	int noteTujuan = a[idx];

	if(binary_search(AdjList[noteTujuan].begin(), AdjList[noteTujuan].end(), nodeSekarang)){
		return dp[idx][nodeSekarang] = solve(idx+1, nodeSekarang);
	}else{
		int ans = inf;
		for(int i=0;i<AdjList[noteTujuan].size();i++){
			int v = AdjList[noteTujuan][i];
			ans = min(ans, 1 + solve(idx+1, v));
		}
		return dp[idx][nodeSekarang] = ans;
	}
}

int main(){
	int n,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(maxn, vi());
	for(i=1;i<=n;i++){
		int banyak;
		scanf("%d",&banyak);
		for(j=0;j<banyak;j++){
			int bil;
			scanf("%d",&bil);
			AdjList[bil].pb(i);
		}
	}
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	int pertama = a[0];
	int ans = inf;
	memset(dp, -1, sizeof dp);
	for(i=0;i<AdjList[pertama].size();i++){
		int node = AdjList[pertama][i];
		ans = min(ans, solve(1, node));
	}
	printf("%d\n",ans);
	return 0;
};