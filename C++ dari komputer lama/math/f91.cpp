#include <bits/stdc++.h>

using namespace std;

int memo[1000010];

int f(int n){
	if(memo[n]!=-1){return memo[n];}
	else if(n <=100){return memo[n] = f(f(n+11));}
	else{return memo[n] = n-10;}
}

int main(){
	int n,i;
	memset(memo,-1,sizeof memo);
	while(scanf("%d",&n),n){
		printf("f91(%d) = %d\n",n,f(n));
	}
	return 0;
}