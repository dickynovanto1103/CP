#include <bits/stdc++.h>

using namespace std;

int memo[105][105];

int binom(int n, int m){
	if(m==0 || m==n) return 1;
	if(memo[n][m]!=-1) return memo[n][m];
	return memo[n][m] = binom(n-1,m) + binom(n-1,m-1);
}

int main(){
	int n,m;
	memset(memo,-1,sizeof memo);
	while(scanf("%d %d",&n,&m),(n||m)){
		printf("%d things taken %d at a time is %d exactly.\n",n,m,binom(n,m));
	}
	return 0;
}