#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
int main(){
	int tc,i,n,a[510],sum,ans,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		ans=inf;
		for(i=0;i<n;i++){
			sum=0; 
			for(j=0;j<n;j++){
				if(i!=j){sum+=abs(a[i]-a[j]);}
			}
			
			ans=min(ans,sum);
			//printf("sum: %d ans: %d\n",sum,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}