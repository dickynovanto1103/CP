#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,i,j,k,l,cnt,b,a;
	char kata[110][110];
	bool found;
	while(scanf("%d",&n),n){
		scanf("%d",&m);
		for(i=0;i<n;i++){scanf("%s",&kata[i]);}

		cnt=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				for(k=i;k<n;k++){
					for(l=j;l<m;l++){
						found=false;
						for(b=i;b<=k && !found;b++){
							for(a=j;a<=l && !found;a++){
								if(kata[b][a]=='0'){found=true;}
							}
						}
						if(!found){cnt++;}
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}