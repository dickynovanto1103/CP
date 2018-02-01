#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,i;
	float d,v,u;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		scanf("%f %f %f",&d,&v,&u);
		printf("Case %d: ",i);
		if(v==0 || v>=u){printf("can't determine\n");}
		else{
			printf("%.3f\n",abs(d/u-d/sqrt(u*u-v*v)));
		}
	}
	return 0; 
}