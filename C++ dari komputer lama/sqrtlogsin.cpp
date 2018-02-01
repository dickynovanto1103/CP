#include <cstdio>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int a[1000010];

int main(){

	int i,n;
	
	a[0]=1;

	for(i=1;i<=1000000;i++){
		a[i]=(a[(int)floor(i-sqrt(i))]+a[(int)floor(log(i))]+a[(int)floor(i*sin(i)*sin(i))])%1000000;
	}
	while(scanf("%d",&n),(n!=-1)){
		printf("%d\n",a[n]);
	}
	return 0;
}