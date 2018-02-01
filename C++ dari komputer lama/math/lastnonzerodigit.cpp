#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
int main(){
	long long n,m,i,hasil;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		hasil = 1;
		for(i=n;i>=n-m+1;i--){
			hasil*=i;
			while(hasil%10==0){hasil/=10;}
			hasil%=inf;
			if(hasil<0){ break;}
			//printf("hasil: %lld\n",hasil);
		}
		//printf("hasil: %d\n",hasil);
		hasil%=10;
		printf("%lld\n",hasil);
	}
	return 0;
}