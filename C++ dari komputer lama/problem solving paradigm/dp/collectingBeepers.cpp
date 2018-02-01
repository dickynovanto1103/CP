#include <bits/stdc++.h>

using namespace std;
int memo[11][1<<11], dist[15][15];
int n;

int solve(int pos, int bitmask){
	int nxt;
	if(bitmask == (1<<n+1)-1){return dist[pos][0];}//jarak dari pos ke awal
	if(memo[pos][bitmask]!=-1){return memo[pos][bitmask];}
	int ans = 2000000000;
	for(nxt=0;nxt<=n;nxt++){
		if(nxt!=pos && !(bitmask & (1<<nxt))){//belum dikunjungi
			ans = min(ans, dist[pos][nxt] + solve(nxt, bitmask | (1<<nxt)));	
		}
	}
	return memo[pos][bitmask] = ans;

}

int main() {
	int tc,i,j,x[13],y[13],r,c;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&r,&c);
		scanf("%d %d",&x[0],&y[0]);
		scanf("%d",&n);
		for(i=1;i<=n;i++){scanf("%d %d",&x[i],&y[i]);}
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
			}
		}
		memset(memo,-1,sizeof memo);
		printf("The shortest path has length %d\n",solve(0,1));
	}
	return 0;
}