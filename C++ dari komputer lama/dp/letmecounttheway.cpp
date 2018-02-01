#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int coin[]={1,5,10,25,50};
ll memo[7][30010];
ll solve(int type,int n){
	if(n==0){return 1;}
	else if(n < 0 || type==5){return 0;}
	else if(memo[type][n]!=-1){return memo[type][n];}
	else{
		return memo[type][n]=solve(type+1,n) + solve(type,n-coin[type]);
	}
}

int main(){
	int n,i;
	ll ans;
	memset(memo,-1,sizeof memo);
	while(scanf("%d",&n)!=EOF){
		
		ans=solve(0,n);
		if(ans==1){printf("There is only 1 way to produce %d cents change.\n",n);}
		else{printf("There are %lld ways to produce %d cents change.\n",ans,n);}
	}
	return 0;
}