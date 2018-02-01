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

const int maxn = 240;
int memo[maxn][maxn];

int solve(int a, int b){
	if(a<=0 || b<=0){return 0;}
	if(a==1 && b==1){return 0;}
	if(memo[a][b]!=-1){return memo[a][b];}
	return memo[a][b] = max(1 + solve(a-2,b+1), 1+ solve(a+1,b-2));
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	memset(memo,-1,sizeof memo);
	int ans = solve(a,b);
	printf("%d\n",ans);
	return 0;
};