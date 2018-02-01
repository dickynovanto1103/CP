#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 51;
int memo[maxn][maxn];
string kata;

int solve(int awal, int akhir){
	if(awal==akhir){return 1;}
	if(awal>akhir){return 0;}
	if(memo[awal][akhir]!=-1){return memo[awal][akhir];}
	if(kata[awal]==kata[akhir]){return memo[awal][akhir] = 2 + solve(awal+1, akhir-1);}
	return memo[awal][akhir] = max(solve(awal+1,akhir), solve(awal,akhir-1));
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	while(n--){
		memset(memo,-1,sizeof memo);
		cin>>kata;
		int ans = solve(0,kata.length()-1);
		printf("%d\n",ans);
	}
	return 0;
}