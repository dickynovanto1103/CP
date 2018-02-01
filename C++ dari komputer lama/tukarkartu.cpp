#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, a[1010],i,j,temp,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	//bubble sort
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
