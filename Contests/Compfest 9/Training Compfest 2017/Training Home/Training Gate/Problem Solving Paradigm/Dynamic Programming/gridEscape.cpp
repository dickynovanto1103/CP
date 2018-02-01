#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const ll mod = 1000000007;

int dist[1001][1001],r,c;
ll memo[1001][1001];
int dx[] = {1,0};
int dy[] = {0,1};

ll solve(int x, int y){
	if(x==r && y==c){return 1;}
	//if(dist[x][y] == inf){return 0;}
	if(memo[x][y]!=-1){return memo[x][y];}
	ll ans = 0;
	for(int i=0;i<2;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		if(xbaru>=1 && xbaru<=r && ybaru>=1 && ybaru<=c){
			if(dist[xbaru][ybaru]!=inf){
				ans+=solve(xbaru,ybaru);
				ans%=mod;
			}
		}
	}
	return memo[x][y] = ans;
}

int main() {
	int n;
	scanf("%d %d %d",&r,&c,&n);
	while(n--){
		int a,b;
		scanf("%d %d",&a,&b);
		dist[a][b] = inf;
	}
	memset(memo,-1,sizeof memo);
	ll ans = solve(1,1) % mod;

	printf("%lld\n",ans);
	return 0;
}