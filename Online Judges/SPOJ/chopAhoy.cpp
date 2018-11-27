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
string kata;
ll dp[26][226][226][2];

ll solve(int idx, int sum, int sumSebelum,int baru){
	if(idx == n){
		if(baru){return 0;}
		if(sum >= sumSebelum){return 1;}
		else{return 0;}
	}
	if(dp[idx][sum][sumSebelum][baru]!=-1){return dp[idx][sum][sumSebelum][baru];}
	int totalBaru = sum + kata[idx] - '0';
	if(totalBaru < sumSebelum){return dp[idx][sum][sumSebelum][baru] = solve(idx+1, totalBaru, sumSebelum, 0);}
	return dp[idx][sum][sumSebelum][baru] = solve(idx+1, totalBaru, sumSebelum,0) + solve(idx+1, 0, totalBaru,1);
}

int main(){
	int tc = 1;
	while(cin>>kata, kata!="bye"){
		memset(dp, -1, sizeof dp);
		n = kata.length();
		printf("%d. %lld\n",tc++, solve(0,0,0,0));
	}
	return 0;
};