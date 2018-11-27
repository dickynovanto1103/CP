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

const int maxn = 505;

int dp[maxn][maxn];
int a[maxn];
int hitam[maxn];
int n,k;

int solve(int idx, int banyakStable){
	
	if(banyakStable == 0){
		if(idx == (n+1)){return 0;}
		else{return inf;}
	}
	int& ans = dp[idx][banyakStable];
	if(ans != -1){return ans;}
	ans = inf;
	for(int i=idx;i<=(n - banyakStable+1);i++){
		int banyakElemen = i-idx+1;
		int banyakHitam = hitam[i] - hitam[idx-1];
		int banyakPutih = banyakElemen - banyakHitam;

		ans = min(ans, banyakHitam*banyakPutih + solve(i+1, banyakStable-1));
	}

	return ans;
}

int main(){
	int i,j;
	memset(dp, -1, sizeof dp);
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		hitam[i] = hitam[i-1];
		if(a[i]){hitam[i]++;}
	}
	int ans = solve(1,k);
	printf("%d\n",ans);
	return 0;
};