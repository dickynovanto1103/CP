#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	int n,a[20],i,tc=1,j,k;
	ll ans,hasilkali;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		//sort(a,a+n);
		ans=0;
		for(i=0;i<n;i++){
			hasilkali=1;
			for(j=i;j<n;j++){
				hasilkali*=a[j];
				ans=max(ans,hasilkali);
			}

		}
		
		printf("Case #%d: The maximum product is %lld.\n\n",tc++,ans);
	}
	return 0;
}