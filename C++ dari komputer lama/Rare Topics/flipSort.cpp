#include <cstdio>

using namespace std;

int main(){
	int n,a[1010],i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int cnt = 0;
		//sort
		for(i=n;i>0;i--){
			for(j=1;j<i;j++){
				//printf("i: %d j = %d\n",i,j);
				if(a[j]<a[j-1]){
					//printf("yang ditukar a[%d]=%d dengan a[%d]=%d\n",j,a[j],j-1,a[j-1]);
					int temp = a[j];
					a[j] = a[j-1];
					a[j-1] = temp;
					cnt++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n",cnt);
	}
	return 0;
}