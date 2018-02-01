#include <bits/stdc++.h>

using namespace std;

int bagidigit(int n){
	int sum=0;
	while(n>0){
		sum+=(n%10);
		n/=10;
	}
	return sum;
}

int main(){
	int n,sum;
	while(scanf("%d",&n),n){
		sum=n;
		while(sum>=10){//masih 2 digit ke atas
			sum=bagidigit(sum);
		}
		printf("%d\n",sum);
	}
	return 0;
}