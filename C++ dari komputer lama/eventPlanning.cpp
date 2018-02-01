#include <cstdio>
#include <iostream>
using namespace std;
#define inf 1000000000
int main(){
	int n,b,h,w,i,j,minim,harga[20], kasur[15];
	while(scanf("%d %d %d %d",&n,&b,&h,&w)!=EOF){
		minim = inf;
		for(i=0;i<h;i++){
			scanf("%d",&harga[i]);
			for(j=0;j<w;j++){
				scanf("%d",&kasur[j]);
				if(kasur[j]>=n){
					int temp = n*harga[i];
					//printf("kasur: %d temp: %d\n",kasur[j],temp);
					if( temp <= b){minim = min(minim, temp);}
				}
			}

		}
		if(minim==inf){printf("stay home\n");}
		else{printf("%d\n",minim);}
	}
	return 0;
}