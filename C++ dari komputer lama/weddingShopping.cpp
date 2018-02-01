#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int price[30][30];
int memo[210][30];
int M,C;
int cost(int money, int g){
	int j;
	if(money<0){
		return -1000;
	}else if(g==C+1){//sudah membeli semua barang
		return M-money;
	}else{
		if(memo[money][g]!=-1){return(memo[money][g]);}
		else{
				int ans=-1;
				for(j=1;j<=price[g][0];j++){
					ans=max(ans,cost(money-price[g][j],g+1));
				}
			return(memo[money][g]=ans);
		}
	}
}

int main(){
	int TC,i,j;
	
	scanf("%d",&TC);
	while(TC--){
		scanf("%d%d",&M,&C);
		for(i=1;i<=C;i++){
			scanf("%d",&price[i][0]);
			for(j=1;j<=price[i][0];j++){
				scanf("%d",&price[i][j]);
			}
		}
		memset(memo,-1,sizeof memo);
		int jawaban;
		jawaban=cost(M,1);
		if(jawaban<0){
			printf("no solution\n");
		}else{
			printf("%d\n",jawaban);
		}
	}
	return 0;
}