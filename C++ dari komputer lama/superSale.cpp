#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int price[1010],weight[1010];
int N;
int memo[1010][35];

int val(int id, int remW){
	if(id==N || remW==0){
		return 0;
	}else{
		if(memo[id][remW]!=-1){return memo[id][remW];}
		else{
			if(weight[id]>remW){return val(id+1,remW);}//swithcing to the other item
			else{return(memo[id][remW]=max(val(id+1,remW),price[id] + val(id+1,remW-weight[id])));}
		}
		
	}
}

int main(){
	int TC,G,i,j,MW,ans;
	scanf("%d",&TC);
	while(TC--){
		memset(memo,-1,sizeof memo);
		ans=0;
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%d %d",&price[i],&weight[i]);
		}
		scanf("%d",&G);
		while(G--){
			scanf("%d",&MW);
			ans+=val(0,MW);
		}
		printf("%d\n",ans);
	}
	return 0;
}