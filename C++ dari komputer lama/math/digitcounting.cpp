#include <bits/stdc++.h>

using namespace std;

int a[10];

void bagi(int n){
	int bil;
	while(n>0){
		bil=n%10;
		a[bil]++;
		n/=10;
	}
}

int main(){
	string kata;
	int tc,i,n;
	
	scanf("%d",&tc);
	while(tc--){
		memset(a,0,sizeof a);
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			bagi(i);
		}
		for(i=0;i<10;i++){
			if(i!=0){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}