#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n,i,a[100010],j, bil;
	scanf("%d",&n);
	int sum = 0, d=1e9;
	for(i=0;i<n;i++){
		scanf("%d",&bil);
		if(bil>0){
			sum+=bil;
			if(bil%2==1){d = min(d,bil);}
		}else{
			if(-bil%2==1){d = min(d,-bil);}
		}
	}
	if(sum%2==1){cout<<sum<<endl;}
	else{cout<<sum-d<<endl;}
	
	return 0;
}