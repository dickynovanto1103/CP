#include<cstdio>

using namespace std;

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		cin>>n;
		int a[101][101];
		for(i=0;i<n;i++){
			for(j=0;j<=i;j++){
				cin>>a[i][j];
			}
		}
		
		for(i=n-1;i>=0;i--){
			dp[i][j] = a[i][j];
			if(i<(n-1)){
				dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
			}
		}
	}
}