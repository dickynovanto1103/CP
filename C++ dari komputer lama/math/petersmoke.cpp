#include <cstdio>

using namespace std;
typedef long long ll;
int main(){
	int n,k,sisa;
	ll ans;
	while(scanf("%d %d",&n,&k)!=EOF){
		ans=n;
		if(n<k){printf("%d\n",n);}
		else{
			n-=k; ans++;
			ans+=(n/(k-1));
			printf("%lld\n",ans);
		}
	}
	return 0;
}