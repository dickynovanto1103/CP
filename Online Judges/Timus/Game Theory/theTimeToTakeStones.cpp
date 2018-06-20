#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,k,i,j;
	int a[100];
	scanf("%d %d",&n,&k);
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
	int dp[10010];
	
	memset(dp,-1,sizeof dp);

	for(i=1;i<=n;i++){
		bool terisi = false;
		for(j=0;j<k;j++){
			if((i-a[j])<0){continue;}
			if(dp[i-a[j]] == 0){dp[i] = 1; terisi = true;break;}
		}
		if(!terisi){
			dp[i] = 0;
		}
		// printf("dp[%d]: %d\n",i,dp[i]);
	}



	if(dp[n]==1){
		printf("1\n");
	}else{
		printf("2\n");
	}

	return 0;
};