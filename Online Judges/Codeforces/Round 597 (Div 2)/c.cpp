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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string s;
	cin>>s;
	int n = s.size();
	int i,j;
	int dp[100001];
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	dp[1] = 1;
	const int mod = 1e9 + 7;
	for(i=0;i<n;i++){
		if(s[i] == 'w' || s[i] == 'm'){printf("0\n"); return 0;}
	}
	for(i=2;i<=n;i++){
		char satu = s[i-1], dua = s[i-2];

		dp[i] += dp[i-1];
		if(satu == dua && (satu == 'u' || satu == 'n')) {
			dp[i] += dp[i-2];
			dp[i] %= mod;
		}
	}
	printf("%d\n",dp[n]);
	return 0;
};