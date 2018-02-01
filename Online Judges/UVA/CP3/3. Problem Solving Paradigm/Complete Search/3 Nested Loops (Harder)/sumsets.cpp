#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a[1010],i,j,k;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a,a+n);
		bool found = false;
		for(i=n-1;i>=0;i--){
			int d = a[i];
			for(j=0;j<n;j++){
				if(a[j]!=d){
					for(k=j+1;k<n;k++){
						if(a[k]!=d){
							int bilcari = d-a[j]-a[k];
							if(bilcari!=d && bilcari!=a[j] && bilcari!=a[k]){
								if(binary_search(a,a+n,bilcari)){found = true; printf("%d\n",d); break;}	
							}
						}

					}	
				}
				if(found){break;}
				
			}
			if(found){break;}
		}
		if(!found){printf("no solution\n");}
	}
	return 0;
}