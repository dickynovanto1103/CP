#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	int t;
	while(b!=0){
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main(){
	int n,i,j,sum;
	//printf("%d\n",gcd(2,4));
	while(scanf("%d",&n),n){
		sum=0;
		for(i=1;i<n;i++){
			for(j=i+1;j<=n;j++){
				int nilai = gcd(i,j);
				sum+=nilai;
				//printf("gcd dari %d %d : %d sum sekarang: %d\n",i,j,nilai,sum);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}