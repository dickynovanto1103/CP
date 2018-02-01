#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int coin[]={1,5,10,25,50};
int memo[6][7500];
#define INF 1000000000

int change(int type, int N){
	if(N==0){
		return(1);
	}else if(N<0 || type==5){
		return(0);
	}else if(memo[type][N]!=-1){
		return(memo[type][N]);
	}else{
		return(memo[type][N]=change(type,N-coin[type])+change(type+1,N));
	}
}


int memoChange[1000];
int minchange(int N){
	int i,best;
	if(N==0){
		return 0;
	}else{
		if(memoChange[N]!=-1){
			return memoChange[N];
		}else{
			best=INF;
			for(i=0;i<5;i++){
				if(coin[i]<=N){
					best=min(best,minchange(N-coin[i])+1);
				}
			}
			return(memoChange[N]=best);
		}
	}
}

int main(){
	int i,N;
	memset(memo,-1,sizeof memo);
	memset(memoChange,-1,sizeof memoChange);
	while(scanf("%d",&N)!=EOF){
		printf("%d\n",change(0,N));
		printf("banyak minimal koin: %d\n",minchange(N));
	}
	return 0;
}