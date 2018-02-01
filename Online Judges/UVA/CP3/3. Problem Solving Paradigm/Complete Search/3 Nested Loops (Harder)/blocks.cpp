#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,i,j,k,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		
		int maks = 1000000000;
		for(i=1;i<=n;i++){
			int bil = n;
			if(bil%i==0){
				bil/=i;
				for(j=i;j<=n;j++){
					int temp = bil;
					if(temp%j==0){
						temp/=j;
						//dpt bil, i dan j
						//cari luas
						//printf("i: %d j: %d bil: %d\n",i,j,temp);
						int luas = 2*(i*j + i*temp + j*temp);
						maks = min(maks, luas);
					}
				}	
			}
			
		}
		printf("%d\n",maks);
	}
	return 0;
}