#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, a[1010],m;
	int tag[100100],i,j;
	memset(tag,0,sizeof tag);
	scanf("%d",&n);
	int sum = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); sum+=a[i];}
	scanf("%d",&m);
	int maks = -1, minmaks = -1;
	for(i=0;i<m;i++){
		int l, r;
		scanf("%d %d",&l,&r);
		maks = max(maks,r);
		minmaks = max(minmaks,l);
		for(j=l;j<=r;j++){tag[j]=1;}
	}
	if(sum>maks){printf("-1\n");}
	else{
		for(i=sum;i<=maks;i++){
			if(tag[i]==1){printf("%d\n",i);break;}
		}
	}
	return 0;
}