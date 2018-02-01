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

const int maxn = 10;

ll memo[maxn][maxn];
int dx[] = {1,0};
int dy[] = {0,1};
int n,m;
ll solve(int a, int b){
	if(a==n-1 && b==m-1){return 1;}
	if(memo[a][b]!=-1){return memo[a][b];}
	ll ans = 0;
	for(int i=0;i<2;i++){
		int x = a+dx[i], y = b+dy[i];
		if(x>=0 && x<n && y>=0 && y<m){
			ans+=solve(x,y);
		}
	}
	return memo[a][b] = ans;
}

int main() {
	scanf("%d %d",&n,&m);
	memset(memo,-1,sizeof memo);
	printf("%lld\n",solve(0,0));
	return 0;
}