#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll n;
	ll k,m;
	ll a[3];
	scanf("%lld",&n);
	if(n%2==1){
		k = (n*n + 1)/2;
		m = (n*n - 1)/2;
	}else{
		k = (n*n)/4 + 1;
		m = k-2;
		//printf("k: %lld, m: %lld\n",k,m);
	}
	a[0] = n; a[1] = k; a[2] = m;
	sort(a,a+3);
	for(int i=0;i<3;i++){
		if(i>0){printf(" ");}
		printf("%lld",a[i]);
	}
	printf("\n");
	return 0;
}