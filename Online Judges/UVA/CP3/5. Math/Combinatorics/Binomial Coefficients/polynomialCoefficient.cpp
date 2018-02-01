#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,k,i;
	ll a[15], fac[15];
	fac[0] = 1;
	for(i=1;i<14;i++){fac[i] = i*fac[i-1];}
	//for(i=0;i<14;i++){printf("i: %d %d\n",i,fac[i]);}
	while(scanf("%d %d",&n,&k)!=EOF){
		int maks = -inf;
		ll sum = fac[n];
		for(i=0;i<k;i++){
			scanf("%lld",&a[i]);
			sum/=fac[a[i]];
		}
		printf("%lld\n",sum);
	}
	

	return 0;
}