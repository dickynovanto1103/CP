#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
int coin[]={1,6,10};
int memo[100];
int solve(int n){
	int ans,i;
	if(n==0){return 0;}
	else if(n<0){return inf;}
	else if(memo[n]!=-1){return memo[n];}
	else{
		ans=inf;
		for(i=0;i<3;i++){
			ans=min(ans,solve(n-coin[i])+1);
		}
		return memo[n]=ans;
	}
}

int main(){
	int n,i,ans=inf;
	memset(memo,-1,sizeof memo);
	scanf("%d",&n);
	
	printf("banyak minimal cara: %d\n",solve(n));
	return 0;
}