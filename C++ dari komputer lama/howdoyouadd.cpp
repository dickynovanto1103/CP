#include <cstdio>
#include <cstring>
using namespace std;

int memo[110][110];

int ways(int N, int K){
	int i;
	if(K==1){return 1;}
	else{
		if(memo[N][K]!=-1){return(memo[N][K]);}
		else{
			int total=0;
			for(i=0;i<=N;i++){
				total=(total+ways(N-i,K-1))%1000000;
			}
			return memo[N][K]=total;
		}
	}
}

int main(){
	int N,i,j,K;
	int way[110][110];//way[N][K]
	memset(memo,-1,sizeof memo);
	while(scanf("%d %d",&N,&K),(N||K)){

		/*for(i=1;i<=N;i++){
			way[i][1]=1;
		}
		for(i=0;i<=K;i++){
			way[0][i]=0;
		}
		for(i=2;i<=N;i++){
			for(j=1;j<=K;j++){

			}
		}*/
		printf("%d\n",ways(N,K));
	}
	return 0;
}