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

const int maxn = 1e2 + 2;

int dp[maxn][maxn];
string kata;

int solve(int kiri, int kanan){
	if(kiri == kanan){return 1;}
	if(kiri > kanan){return 0;}
	int& ans = dp[kiri][kanan];
	if(ans != -1){return ans;}
	if((kata[kiri] == '(' && kata[kanan] == ')') || (kata[kiri] == '[' && kata[kanan] == ']')){
		return ans = solve(kiri+1, kanan-1);
	}else{
		return ans = min(1 + solve(kiri+1, kanan), min(1 + solve(kiri, kanan-1), 2 + solve(kiri+1, kanan-1)));
	}

}

int main(){
	cin>>kata;
	if(kata == ""){printf("0\n"); return 0;}
	memset(dp, -1, sizeof dp);
	int pjg = solve(0, (int)kata.length()-1);
	printf("%d\n", pjg);
	return 0;
};