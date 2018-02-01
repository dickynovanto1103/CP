#include <cstdio>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
	double V,Vs;
	double hasil,compute;
	double memo[60010];
	bool found;
	int i,j,idxMax;
	while(scanf("%lf %lf",&V,&Vs), (V||Vs)){
		i=1;hasil=-1;found=true;
		if(V<=Vs)
			found=false;
		while((V/(double)i>Vs)&&found){
			compute=(0.3*sqrt(V/(double)i-Vs))*(double)i;
			if(hasil<compute){hasil=compute;idxMax=i;}
			memo[i]=compute;
			for(j=idxMax+1;j<i;j++){
				if(hasil==memo[j]){found=false;break;}
			}
			if(found){i++;}
		}
		if(!found){
			printf("0\n");
		}else{
			printf("%d\n",idxMax);
		}
	}
	return 0;
}