#include <cstdio>
#include <iostream>
using namespace std;
#define inf 1000000000
int parse(string kata){
	int bil = 0;
	int temp;
	for(int i = 0; i < kata.length(); i++) {
		bil*=10;
		temp = kata[i]-48;
		bil+=temp;
	}
	return bil;
}

int main() {
	int n,i,j,k,a[110][110],bil;
	string kata;
	//scanf("%d",&bil);
	//printf("bil: %d\n",bil);
	scanf("%d",&n);

	for(i=2;i<=n;i++){
		for(j=1;j<i;j++){
			cin>>kata;
			if(kata[0]=='x'){a[i][j] = inf; a[j][i] = inf;}
			else{
				bil = parse(kata);
				a[i][j] = a[j][i] = bil;
			}
		}
	}
	for(i=1;i<=n;i++){a[i][i]=0;}

	//floyd
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	int ans = -1;
	for(i=2;i<=n;i++){ans = max(ans, a[1][i]);}
	printf("%d\n",ans);
	return 0;
}