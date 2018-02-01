#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,tc,i,j,a[21],p,sum;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&p);
		for(i=0;i<p;i++){scanf("%d",&a[i]);}
		for(i=0;i<(1<<p);i++){
			sum=0;
			for(j=0;j<p;j++){
				if(i & (1 << j)){
					sum+=a[j];
				}
			}
			if(sum==n){break;}
		}
		if(sum==n){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
}