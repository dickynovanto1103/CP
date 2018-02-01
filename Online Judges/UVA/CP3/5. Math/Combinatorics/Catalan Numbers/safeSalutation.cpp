#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,a[12];
	a[0] = 1;
	for(i=1;i<=10;i++){
		a[i] = (2*i*(2*i-1)*a[i-1])/((i+1)*i);
	}
	int test = 1;
	while(scanf("%d",&n)!=EOF){
		if(test==2){printf("\n");}
		printf("%d\n",a[n]);
		test = 2;
	}
	return 0;
}