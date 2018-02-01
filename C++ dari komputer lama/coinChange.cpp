#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define INF 1000000000
#define JumlahKoin 5
int coin[]={50,25,10,5,1};
bool hasMarked[5000];
int memo[5000];
int total,N;

int changeNaive(int N){
	int i,best;
	if(N==0){
		return(0);
	}else{
		best=INF;
		for(i=0;i<5;i++){
			if(coin[i]<=N){
				best=min(best,changeNaive(N-coin[i])+1);
			}
		}
		return(best);
	}
}



int changeTopDown(int N){
	int best,i;

	if(N==0){
		return(0);
	}else if(hasMarked[N]){
		return(memo[N]);
	}else{
		best=INF;
		for(i=0;i<5;i++){
			if(coin[i]<=N){
				best=min(best,changeTopDown(N-coin[i])+1);
			}
		}
		hasMarked[N]=true;
		memo[N]=best;
		return(best);
	}
}
int f[7500];
int changeBottomUp(int N){
	int best,i,j;
	f[0]=0;//basecase kalau uang 0 ya butuh 0 koin
	for(i=1;i<=N;i++){//dari 1 cent sampe N cent
		best=INF;
		for(j=0;j<JumlahKoin;j++){
			if(coin[j]<=i){
				best=min(best,(f[i-coin[j]])+1);
			}
		}
		f[i]=best;
	}
	return(f[N]);
}

int memoways[6][7500];

int ways(int type,int V){
	if(V==0) return 1;
	if(V<0 || type==JumlahKoin) return 0;
	if(memoways[type][V]!=-1) return memoways[type][V];
	return memoways[type][V]=ways(type+1,V)+ways(type,V-coin[type]);
}

int waysTopDown(int type,int N){
	if(N==0){
		return 1;
	}else if(N<0 || type==JumlahKoin){
		return 0;
	}else if(memoways[type][N]!=-1){
		return(memoways[type][N]);
	}else{
		memoways[type][N]=waysTopDown(type+1,N)+waysTopDown(type,N-coin[type]);
	}
	return(memoways[type][N]);
}



int waysBottomUp(int N){
	int i,j,count=0;
	f[0]=1;
	for(i=1;i<=N;i++){
		for(j=0;j<JumlahKoin;j++){
			if(i>=coin[j]){
				count+=f[i-coin[j]];
			}
		}
		f[i]=count;//pengisian tabel dp
		count=0;
	}
	return(f[N]);
}

int main(){
	int i;
	//memset(memoways,-1,sizeof memoways);//initialize
	memset(memoways,-1,sizeof memoways);
	memset(f,0,sizeof f);
	while(scanf("%d",&N)!=EOF){
		//printf("%d\n",changeBottomUp(N));

		//printf("%d\n",waysTopDown(0,N));
		printf("%d\n",waysBottomUp(N));
	}
	
	return 0;
}