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

int n;
double m;
ll a[101];
ll dp[101][20001][2];
ll convert[100000];

ll solve(int idx, int indeksConvert, int isSkipped){
	if(idx >= n)
		return 0;
	if(dp[idx][convert[indeksConvert]][isSkipped]==-1){
		if(isSkipped){
			dp[idx][convert[indeksConvert]][isSkipped] = max(min(a[idx], convert[indeksConvert]) + solve(idx+1, indeksConvert+1, 0), solve(idx+1, 0, 0));
		}else{
			dp[idx][convert[indeksConvert]][isSkipped] = max(min(a[idx], convert[indeksConvert]) + solve(idx+1, indeksConvert + 1, 0), max(solve(idx+1, max(indeksConvert-1,0), 1), solve(idx+2, 0, 0)));
		}
	}
	return dp[idx][convert[indeksConvert]][isSkipped];
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d %lf", &n, &m);
	double hasilKurang[100000];
	hasilKurang[0] = m;
	convert[0] = m;
	for(int i=1;i<200;i++){
		convert[i] = (convert[i-1]*2) / 3;
	}


	for(int i=0;i<n;i++){
		scanf("%lld", a+i);
	}
	printf("%lld\n", solve(0, 0, 1));
	return 0;
};