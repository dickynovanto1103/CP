#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int lcs(string kata1, string kata2, int m, int n){
	int i,j,k;
	int a[110][110];
	string kata[110][110];
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0){a[i][j]=0; kata[i][j]="";}
			else if(kata1[i-1]==kata2[j-1]){a[i][j] = a[i-1][j-1] + 1; kata[i][j]}
			else {
				a[i][j] = max(a[i-1][j], a[i][j-1]);
			}
		}
	}

	//tampilkan matriks
	/*for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	return a[m][n];
}

int main(){
	string kata1,kata2;
	int m,n,tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&m,&n);
		cin>>kata1>>kata2;
		printf("%d\n",lcs(kata1,kata2,m,n));	
	}
	
	return 0;
}