#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,i,a,b,j,sum;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		sum=0;
		scanf("%d %d",&a,&b);
		
		for(j=a;j<=b;j++){
			if(j%2==1){sum+=j;}
		}
		printf("Case %d: %d\n",i,sum);
	}
	return 0;
}