#include <bits/stdc++.h>

using namespace std;

bool isNotIncreasing(int a[], int n){
	for(int i=0;i<n-1;i++){
		if(a[i] >= a[i+1]){return true;}
	}
	return false;
}

int main(){
	int n,m,a[230],b[230],i,j;
	int listnol[230],cnt;
	scanf("%d %d",&n,&m);
	cnt=0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); if(a[i]==0){listnol[cnt] = i; cnt++;}}
	for(i=0;i<m;i++){scanf("%d",&b[i]);}
	sort(b,b+m);
	reverse(b,b+m);
	bool found = false;
	do{

		for(i=0;i<cnt;i++){
			int idx = listnol[i];
			a[idx] = b[i];
		}
		if(isNotIncreasing(a,n)){found = true; break;};
	}while(prev_permutation(b,b+m));

	if(found){printf("Yes\n");}
	else{printf("No\n");}
	return 0;
}