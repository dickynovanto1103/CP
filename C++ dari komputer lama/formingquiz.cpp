#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000.0
int n,target;
double dist[200][200],memo[1 << 16];
double matching(int bitmask){
	int i,j;
	if(bitmask==target){return memo[bitmask]=0;}
	if(memo[bitmask]>=0){return memo[bitmask];}

	double ans = inf;
	for(i=0;i<2*n;i++){
		if(!(bitmask & (1 << i))){break;}
	}
	//ketemu i
	for(j=i+1;j<2*n;j++){
		if(!(bitmask & (1 << j))){
			//try all j possibilities ..search the min ans
			ans= min(ans,dist[i][j] + matching(bitmask | (1 << i) | (1 << j)));
		}
	}
	return memo[bitmask] = ans;
}

int main(){
	int tc=1,i,j,x[20],y[20],E;
	double mst;
	while(scanf("%d",&n),n){
		//attempt using greedy(minimum spanning forest) turns out to be wrong..not optimal
		for(i=0;i<2*n;i++){
			scanf("%*s %d %d",&x[i],&y[i]);//skips name..

		}
		for(i=0;i<2*n-1;i++){
			for(j=i+1;j<2*n;j++){
				dist[i][j]=dist[j][i]=hypot(x[i]-x[j],y[i]-y[j]);
			}
		}
		target=(1 <<(2*n))-1;
		memset(memo,-1.0,sizeof memo);
		printf("Case %d: %.2lf\n",tc++,matching(0));

	}
	return 0;
}