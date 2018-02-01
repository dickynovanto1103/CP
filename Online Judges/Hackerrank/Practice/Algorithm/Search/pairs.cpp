#include <bits/stdc++.h>

using namespace std;


int main(){
	int n,k,i,j;
	int a[100010];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	i=0,j=1;
	int cnt = 0;
	while(i<n && j<n){
		if(a[j] - a[i]>k){i++;}
		else if(a[j]-a[i] < k){j++;}
		else{cnt++; i++; j++;}
	}
	printf("%d\n",cnt);
	return 0;
}