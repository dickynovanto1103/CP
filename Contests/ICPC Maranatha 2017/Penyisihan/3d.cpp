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

int a,b,c;
ll memo[15][15][15];
int dx[]={1,0,0};
int dy[]={0,1,0};
int dz[]={0,0,1};

ll solve(int x, int y, int z){
	if(x==a&&y==b&&z==c){return 1;}
	if(memo[x][y][z]!=-1){return memo[x][y][z];}
	ll ans = 0;
	for(int i=0;i<3;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i], zbaru = z+dz[i];
		if(xbaru>=0 && xbaru<=a && ybaru>=0 && ybaru<=b && zbaru>=0 && zbaru<=c){
			ans+=solve(xbaru,ybaru,zbaru);
		}
	}
	return memo[x][y][z] = ans;
}

int main() {
	
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		memset(memo,-1,sizeof memo);
		ll ans = solve(0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}