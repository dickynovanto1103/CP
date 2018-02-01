#include <bits/stdc++.h>

using namespace std;
int a[10];
int main(){
	int n,i,bil,idx,ans;
	for(i=1;i<=5;i++){a[i]=0;}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&bil);
		a[bil]++;
	}
	idx = -1; ans = -1;
	for(i=1;i<=5;i++){if(ans < a[i]){ans = a[i]; idx = i;}}
	printf("%d\n",idx);
	return 0;
}