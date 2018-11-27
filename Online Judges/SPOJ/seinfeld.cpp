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

const int maxn = 2e3 + 3;

int dp[maxn][maxn];
int n;
string kata;
int solve(int idx, int nilai){
	// printf("kata[%d]: %c\n", idx,kata[idx]);

	if(idx==n){
		if(nilai == 0){
			// printf("halo\n");
			return 0;
		}
		else{return inf;}
	}
	if(nilai < 0){
		return inf;
	}
	// printf("halo1 dp[%d][%d]: %d\n",idx,nilai,dp[idx][nilai]);
	if(dp[idx][nilai]!=-1){return dp[idx][nilai];}
	// printf("halo2\n");
	if(kata[idx] == '{'){
		return dp[idx][nilai] = min(solve(idx+1,nilai+1), 1 + solve(idx+1, nilai-1));
	}else{
		// printf("idx: %d halo\n",idx);
		return dp[idx][nilai] = min(solve(idx+1,nilai-1), 1 + solve(idx+1, nilai+1));
	}
	
}

int main(){
	int tc = 1;
	while(cin>>kata, kata[0]!='-'){
		memset(dp, -1, sizeof dp);
		n = kata.length();
		// int nilaiAwal = (kata[0] == '{' ? 1: -1);
		// printf("nilaiAwal: %d\n",nilaiAwal);
		int ans = solve(0, 0);
		printf("%d. %d\n",tc,ans);
		tc++;
	}
	return 0;
};