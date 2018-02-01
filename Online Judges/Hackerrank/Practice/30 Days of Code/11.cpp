#include <bits/stdc++.h>

using namespace std;

int main(){
	int j,i;
	int a[6][6];
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int sum, ans=-1000;
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			sum = 0;
			sum = sum+a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
			ans = max(ans,sum);
		}
	}
	printf("%d\n",ans);
	return 0;
}