#include <cstdio>
using namespace std;

int main(){
	int n,a[50],avg,total,ans,i,test=1;
	while(scanf("%d",&n),n){
		
		total=0;
		for(i=0;i<n;i++){scanf("%d",&a[i]);total+=a[i];}
		avg=total/n;
		//printf("avg: %d\n",avg);
		ans=0;
		for(i=0;i<n;i++){
			if(a[i]>avg){ans+=(a[i]-avg);}
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",test++,ans);
	}
	return 0;
}