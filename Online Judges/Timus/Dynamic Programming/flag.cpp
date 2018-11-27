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

ll dp[50][3][3];
int n;

const int merah = 2;
const int biru = 1;
const int putih = 0;

ll solve(int idx, int warnaSekarang, int warnaSebelum){
	if(idx == (n-1)){
		if(warnaSekarang == biru){return 0;}
		else{return 1;}
	}
	ll& ans = dp[idx][warnaSekarang][warnaSebelum];
	if(ans != -1){return ans;}
	ans = 0;
	if(warnaSekarang == merah){
		return ans = solve(idx+1, biru, merah) + solve(idx+1, putih, merah);
	}else if(warnaSekarang == putih){
		return ans = solve(idx+1, biru, putih) + solve(idx+1, merah, putih);
	}else{
		if(warnaSebelum == putih){
			return ans = solve(idx+1, merah, biru);
		}else{
			return ans = solve(idx+1, putih, biru);
		}
	}
}

int main(){
	int i,j;
	scanf("%d",&n);
	memset(dp, -1, sizeof dp);
	ll ans = solve(0,putih,putih);
	ans += solve(0, merah, merah);
	printf("%lld\n", ans);
	return 0;
};