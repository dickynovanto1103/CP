#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr[110][110];

int lcs(int kata1[], int kata2[], int m, int n){
	int i,j,k;
	int maks = max(m,n);
	int a[110][110];
	
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0){a[i][j]=0;}
			else if(kata1[i-1]==kata2[j-1]){
				a[i][j] = a[i-1][j-1] + 1;
			 	for(k=0;k<arr[i-1][j-1].size();k++){arr[i][j].push_back(arr[i-1][j-1][k]);}//copy dari sebelumnya
			 	arr[i][j].push_back(kata1[i-1]);//tambahin yang sama
			}
			else {
				if(a[i-1][j] > a[i][j-1]){
					for(k=0;k<arr[i-1][j].size();k++){arr[i][j].push_back(arr[i-1][j][k]);}//copy dari sebelumnya
				}else{
					for(k=0;k<arr[i][j-1].size();k++){arr[i][j].push_back(arr[i][j-1][k]);}//copy dari sebelumnya
				}
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
	int kata1[110],kata2[110];
	int m,n,tc,i;
	
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){scanf("%d",&kata1[i]);}
	for(i=0;i<n;i++){scanf("%d",&kata2[i]);}
	//printf("%d\n",lcs(kata1,kata2,m,n));
	int banyak = lcs(kata1,kata2,m,n);
	//printf("banyak: %d\n",banyak);
	for(i=0;i<banyak;i++){
		//printf("i: %d\n",i);
		if(i==0){printf("%d",arr[m][n][i]);}
		else{printf(" %d",arr[m][n][i]);}
	}
	printf("\n");
	
	return 0;
}