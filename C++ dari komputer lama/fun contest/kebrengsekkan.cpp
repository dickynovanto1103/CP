#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x,i,a[110],cnt=0,sum=0;
	scanf("%d %d",&n,&x);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	for(i=0;i<n;i++){
		sum+=a[i];
		if(sum>x){break;}
		else{cnt++;}
	}
	printf("%d\n",cnt);

	return 0;
}