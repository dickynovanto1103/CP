#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ii pas[41];
int n,m;
int memo[301][301];

int solve(int x, int y){
	double hasil = hypot(x,y);
	int i;
	if(hasil>m){return inf;}
	else if(hasil==m){return 0;}
	if(memo[x][y]!=-1){return memo[x][y];}
	else{
		int best = inf;
		for(i=0;i<n;i++){
			best = min(best, solve(x+pas[i].first,y+pas[i].second)+1);
		}
		return memo[x][y] = best;
	}
}

int main() {
	int i,j,tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){scanf("%d %d",&pas[i].first,&pas[i].second);}
		memset(memo,-1,sizeof memo);
		int ans = solve(0,0);
		if(ans==inf){printf("not possible\n");}
		else{printf("%d\n",ans);}
	}
	return 0;
}