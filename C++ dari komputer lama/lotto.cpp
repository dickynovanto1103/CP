#include <bits/stdc++.h>

using namespace std;

int main(){
	int k,i,arr[15],a,b,c,d,e,f,g;
	g=0;
	while(scanf("%d",&k),k){
		if(g>0){printf("\n");}
		for(i=1;i<=k;i++){scanf("%d",&arr[i]);}
		//proses
		for(a=1;a<=k;a++){
			for(b=a+1;b<=k;b++){
				for(c=b+1;c<=k;c++){
					for(d=c+1;d<=k;d++){
						for(e=d+1;e<=k;e++){
							for(f=e+1;f<=k;f++){
								printf("%d %d %d %d %d %d\n",arr[a],arr[b],arr[c],arr[d],arr[e],arr[f]);
							}
						}
					}
				}
			}
		}
		g=1;
	}
	

	return 0;
}