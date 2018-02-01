#include <cstdio>

using namespace std;

int main(){
	int tc,i,n,a[1000],cnt,sum;
	double avg;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		sum=cnt=0;
		for(i=0;i<n;i++){scanf("%d",&a[i]); sum+=a[i];}
		avg = (double)sum / (double) n;
		for(i=0;i<n;i++){
			if((double)a[i]>avg){cnt++;}
		}
		avg = (double)cnt*100.0/(double)n ;
		printf("%.3lf%%\n",avg);
	}
}