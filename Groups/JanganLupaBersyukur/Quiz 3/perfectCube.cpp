#include <bits/stdc++.h>

using namespace std;

int main(){
	int i,j,k,l;
	for(i=6;i<=200;i++){
		double lhs = pow(i,3);
		for(j=2;j<i;j++){
			for(k=j;k<i;k++){
				double temp = pow(j,3)+pow(k,3);
				if(temp>lhs){break;}
				for(l=k;l<i;l++){
					double total = temp+pow(l,3);
					
					if(lhs<total){break;}
					else if(lhs==total){
						//printf("lhs= %.2lf total: %.2lf\n",lhs,total);
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
					}
				}
			}
		}
	}
	return 0;
}