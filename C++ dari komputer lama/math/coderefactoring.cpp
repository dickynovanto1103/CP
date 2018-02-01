#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,n,i,j,cnt;
	scanf("%d",&tc);
	for(j=1;j<=tc;j++){
		cnt=0;
		scanf("%d",&n);
		printf("Case #%d: %d = ",j,n);
		for(i=2;i<=n;i++){
			if(n%i==0){
				cnt++;
				printf("%d * %d",i,n/i);
				if(cnt==1){printf(" = ");}
				else if(cnt==2){break;}
			}
			
			
		}
		printf("\n");
	}
	return 0;
}