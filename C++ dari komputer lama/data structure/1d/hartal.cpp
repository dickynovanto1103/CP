#include <cstdio>

using namespace std;

int main(){
	int tc,n,p,h,a[4000],i,j,cnt;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d %d",&n,&p);
		for(i=1;i<=n;i++){a[i]=0;}
		cnt=0;
		for(i=0;i<p;i++){
			scanf("%d",&h);
			for(j=h;j<=n;j+=h){
				if(a[j]==0){
					if(!(j%7==6 || j%7==0)){
						cnt++; a[j]=1;//printf("j: %d\n",j);
					}
					
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}