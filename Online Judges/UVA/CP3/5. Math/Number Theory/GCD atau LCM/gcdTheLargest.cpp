#include <bits/stdc++.h>

using namespace std;

long long gcd(int a, int b){return b==0? a: gcd(b,a%b);}

int main(){
	int tc;
	long long n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%ld",&n);
		long long ans = n/2;
		printf("%lld\n",ans);
	}
	return 0;
}