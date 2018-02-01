#include <cstdio>

using namespace std;

int main(){
	int a[1010],cnt,tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		cnt=0;
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		
		for(i=2;i<=n;i++){
			for(j=1;j<i;j++){
				if(a[j]<=a[i]){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}