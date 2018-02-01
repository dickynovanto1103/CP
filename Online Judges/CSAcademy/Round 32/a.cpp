#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i;
	int a[11];
	scanf("%d",&n);
	for(i=1;i<=3;i++){a[i] = i;}
	a[4] = 1; a[5] = 2; a[6] = 3; a[7] = 1; a[8] = 2; a[9] = 3; a[10] = 4;

	int idx = n%10;
	if(idx==0){idx=10;}
	printf("%d\n",a[idx]);
	return 0;
}