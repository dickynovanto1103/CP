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
const int maxn = 2e5 + 5;
int dp[maxn][3];
string kata;

int solve(int idx, int bil){
	if(idx == n){return 0;}
	if(dp[idx][bil] != -1){return dp[idx][bil];}
	if(bil == 0){
		int next = kata[idx+1] - '0';
		return dp[idx][bil] = 1 + solve(idx+1, next % 3);
	}else{
		int next = kata[idx+1] - '0';
		int ans1 = solve(idx+1, next % 3);
		int ans2 = solve(idx+1, (bil*10 + next) % 3);
		return dp[idx][bil] = max(ans1,ans2);
	}
}

int main(){
	
	cin>>kata;
	n = kata.length();
	kata+="0";
	memset(dp, -1, sizeof dp);
	int bilPertama = kata[0] - '0';
	int ans = solve(0, bilPertama%3);
	printf("%d\n",ans);
	return 0;
};