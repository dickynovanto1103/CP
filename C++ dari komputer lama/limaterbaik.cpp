#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int t,n,a[100010],i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int ans=0;
		for(i=n-1;i>=n-5;i--){ans+=a[i];}
		printf("%d\n",ans);
	}
	return 0;
}