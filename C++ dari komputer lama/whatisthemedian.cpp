#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	int a[10000],temp[10000],i=1,idx;
	long long ans;
	double hasil;
	while(scanf("%d",&a[i])!=EOF){
		for(idx=1;idx<=i;idx++){temp[idx]=a[idx];}
		/*printf("i %d:\n",i);
		for(idx=1;idx<=i;idx++){printf("%d ",temp[idx]);}*/
		sort(temp+1,temp+idx);
		/*printf("idx %d:\n",idx-1);
		for(idx=1;idx<=i;idx++){printf("%d ",temp[idx]);}
		printf("\n");*/
		int cnt = idx-1;
		if(cnt%2==0){
			hasil = ((double)temp[cnt/2]+(double)temp[cnt/2 +1])/2.0;
			ans = (long long)floor(hasil);
		}else{
			ans = temp[cnt/2 +1];
		}
		printf("%lld\n",ans);
		i++;
		
	}
	return 0;
}