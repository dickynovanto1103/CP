#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j,temp,bil,simpanj,simpani,tc=0;
	bool found;
	int target = (1 << 10)-1;
	//printf("target: %d\n",target);
	while(scanf("%d",&n),n){
		found=false;
		if(tc){printf("\n");}
		for(i=1234;i<=98765/n;i++){
			j=n*i; temp=0; simpanj=j; simpani=i;
			//printf("j: %d\n",j);
			if(i<10000){temp=1;}
			while(j){bil=j%10; temp|=(1<<bil); j/=10;}
			while(simpani){bil=simpani%10; temp|=(1<<bil); simpani/=10;}
			//printf("i: %d temp: %d\n",i,temp);
			if(temp==target){
				found=true;
				printf("%.5d / %.5d = %d\n",simpanj,i,n);
			}
		}
		if(!found){printf("There are no solutions for %d.\n",n);}
		tc=1;
	}
	return 0;
}