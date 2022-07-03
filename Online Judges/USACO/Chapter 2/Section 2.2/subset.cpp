/*
ID: dickyno1
LANG: C++14
TASK: subset
*/

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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll dp[40][40*41/2];

ll solve(int n, int remSum) {
	if(n == 0){
		if(remSum == 0) {
			return 1;
		}else{
			return 0;
		}
	}

	if(dp[n][remSum] != -1){return dp[n][remSum];}

	return dp[n][remSum] = solve(n-1, remSum - n) + solve(n-1, remSum);
}

int main(){
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);

	int n,i,j;
	scanf("%d",&n);
	// printf("n: %d\n/", n);
	int sum = n*(n+1)/2;
	if(sum % 2 == 1){
		puts("0");
		return 0;
	}

	memset(dp, -1, sizeof dp);
	printf("%lld\n", solve(n, sum/2) / 2);
	
	return 0;
};