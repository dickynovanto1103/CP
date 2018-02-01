#include <bits/stdc++.h>

using namespace std;
#define max1 105

int dp[max1][max1],cnt[max1][max1];

int find(int i,int j){
	if(i==0 || j==0){return 0;}
	else{
		if(dp[i][j]!=-1){return dp[i][j];}
		else{
			return(dp[i][j]=max(find(i-1,j),find(i,j-1))+cnt[i][j]);
		}
	}
}

int main(){
	int l,m,i,j,n,ans;
	
	while(scanf("%d",&n),n){
		memset(dp,-1,sizeof dp);
		memset(cnt,0,sizeof cnt);
		while(n--){
			scanf("%d %d",&l,&m);
			cnt[l][m]++;
		}
		ans=0;
		for(i=0;i<=100;i++){
			for(j=0;j<=100;j++){
				ans=max(ans,find(i,j));
			}
		}
		printf("%d\n",ans);
	}
	printf("*\n");
	return 0;
}