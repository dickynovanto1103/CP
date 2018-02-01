#include <bits/stdc++.h>

using namespace std;
#define maxn 5010
int main(){
	int a[maxn],h[maxn],b[maxn],i=0,j,idx,x,y,z;
	while(scanf("%d %d %d",&x,&y,&z)!=EOF){a[i]=x;h[i]=y;b[i]=z;i++;}
	idx=i;
	int awal=0,akhir=0;
	printf("%d %d",a[0],h[0]);
	for(i=1;i<idx;i++){
		if(a[i]>=a[awal] && a[i]<=a[akhir]){
			for(j=i;j<idx;j++){
				if(h[j])
			}
		}
	}
	
	return 0;
}