#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
int a[110],memo[10010];

int solve(int n){
	int ans,i;
	if(n==0){return 0;}
	else if(n<0){return inf;}
	else if(memo[n]!=-1){return memo[n];}
	else{
		ans=inf;
		for(i=1;i<=100;i++){
			ans=min(ans,1+solve(n-(a[i]*a[i])));
		}
		return memo[n]=ans;
	}
}

int main(){
	int i,n,tc;
	scanf("%d",&tc);
	memset(memo,-1,sizeof memo);
	for(i=1;i<=100;i++){a[i]=i;}
	while(tc--){
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
	return 0;
}