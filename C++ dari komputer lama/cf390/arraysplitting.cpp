#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a[110],i,j,k,sum=0;
	bool found=false;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);sum+=a[i];}
	if(sum!=0){printf("YES\n1\n1 %d\n",n);}
	else{
		for(i=1;i<=n;i++){
			sum=0;
			for(j=i;j<=n;j++){
				for(k=1;k<=j;k++){sum+=a[k];}
				if(sum!=0){
					printf("YES\n2\n1 %d\n%d %d\n",j,j+1,n);
					found=true;
					break;
				}
			}
			if(found){break;}
		}
		if(!found){printf("NO\n");}
	}
	return 0;
}