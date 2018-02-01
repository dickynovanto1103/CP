#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int uang[25];
ll memo[25][10000];
ll solve(int type, int n){
	if(n==0){return 1;}
	else if(type > 21 || n < 0){return 0;}
	else if(memo[type][n]!=-1){return memo[type][n];}
	else{return memo[type][n]=solve(type+1,n) + solve(type,n-uang[type]);}
}



int main(){
	int i,n;
	ll ans;

	memset(memo,-1,sizeof memo);
	for(i=1;i<=21;i++){
		uang[i]=i*i*i;
	}
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",solve(1,n));
	}
	return 0;
}