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

const int maxn = 104;

int n,k;
int a[maxn];
int dp[101][101][101];

int solve(int jumlahPaket, int idx, int sisaBerat){
	if(sisaBerat < 0){return inf;}
	if(jumlahPaket > n){return inf;}
	if(idx == k){
		if(sisaBerat == 0 && jumlahPaket <= n){return 0;}
		else{return inf;}
	}
	if(dp[jumlahPaket][idx][sisaBerat]!=-1){return dp[jumlahPaket][idx][sisaBerat];}
	if(a[idx] == -1){return dp[jumlahPaket][idx][sisaBerat] = solve(jumlahPaket, idx+1, sisaBerat);}
	int ans1 = solve(jumlahPaket, idx+1, sisaBerat);
	int ans2 = a[idx] + solve(jumlahPaket + 1, idx+1, sisaBerat - (idx+1));
	int ans3 = a[idx] + solve(jumlahPaket + 1, idx, sisaBerat - (idx+1));
	return dp[jumlahPaket][idx][sisaBerat] = min(ans1, min(ans2,ans3));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<k;i++){
			scanf("%d",&a[i]);
		}
		memset(dp,-1, sizeof dp);
		int ans = solve(0, 0, k);
		if(ans >= inf){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
};