#include <cstdio>

using namespace std;

int main(){
	int tc,i,n,a[50],test=1,h,taller,shorter;
	scanf("%d",&tc);
	while(tc--){
		printf("Case %d: ",test++);
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		h=a[0]; taller=shorter=0;
		for(i=1;i<n;i++){
			if(a[i]>h){taller++;}
			else if(a[i]<h){shorter++;}
			h=a[i];
		}
		printf("%d %d\n",taller,shorter);
	}
	return 0;
}