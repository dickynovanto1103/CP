#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	int tc,i;
	ll n,m,hasil;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&m);
		if(n>=m){printf("0\n");}
		else{
			hasil=1;
			for(i=n;i>=1;i--){
				hasil*=i;
				//printf("hasil: %lld\n",hasil);
				hasil%=m;
				//printf("hasil setelah dimod: %lld\n",hasil);
			}
			printf("%lld\n",hasil);
		}
	}
	return 0;
}