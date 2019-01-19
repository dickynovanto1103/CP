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

vector<int> AdjList[30010];

int dp[30010];
vi listBegin;

int solve(int idx){
	if(idx >= 30001){return 0;}
	int& ans = dp[idx];
	if(ans != -1){return ans;}
	ans = 0;
	for(int i=0;i<AdjList[idx].size();i++){
		int akhir = AdjList[idx][i];
		int indeks = lower_bound(listBegin.begin(), listBegin.end(), akhir+1) - listBegin.begin();
		int idxButuh = listBegin[indeks];
		ans = max(ans, 1 + solve(idxButuh));
	}
	int indeks = lower_bound(listBegin.begin(), listBegin.end(), idx+1) - listBegin.begin();
	int idxButuh = listBegin[indeks];
	// printf("idxButuh: %d idx: %d\n",idxButuh, idx);
	ans = max(ans, solve(idxButuh));
	return ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		listBegin.pb(a);

		AdjList[a].pb(b);
	}
	listBegin.pb(50000);
	sort(listBegin.begin(), listBegin.end());
	memset(dp,-1,sizeof dp);
	int ans = solve(1);
	printf("%d\n",ans);
	return 0;
};