#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,a[110],maks,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	if(n==1){printf("0\n");}
	else{
		maks=-1; sum=0;
		for(i=0;i<n;i++){maks=max(maks,a[i]);}
		for(i=0;i<n;i++){sum+=abs(maks-a[i]);}
		printf("%d\n",sum);
	}
	return 0;
}