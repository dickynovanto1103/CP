#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int tc,r,a[4],i,j,maks;
	scanf("%d",&tc);
	for(i=0;i<tc;i++){
		printf("Case #%d: ",i+1);
		maks = -1;
		for(j=0;j<4;j++){scanf("%d",&a[j]); maks = max(maks,a[j]);}
		scanf("%d",&r);
		if(maks>r){printf("new record!\n");}
		else{printf("no new record\n");}
	}
	return 0;
}