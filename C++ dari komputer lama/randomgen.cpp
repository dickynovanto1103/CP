#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j;
	int a[80][80];
	srand(time(NULL));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			a[i][j]=rand() % 100;
		}
	}
	printf("%d %d\n",n,n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("%d %d\n",n,n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			a[i][j]=rand() % 100;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}