#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc, i,j;
	ll n;
	ll fib[100];
	fib[0] = 1; fib[1] = 2;
	for(i=2;;i++){
		fib[i] = fib[i-1] + fib[i-2];
		// printf("fib[%d]: %lld\n",i,fib[i]);
		if(fib[i]>=4e16){
			break;
		}
	}
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&n);
		ll tot = 0;
		for(i=0;;i++){
			if(fib[i]>n){break;}
			if(fib[i]%2==0){tot+=fib[i];}
		}
		printf("%lld\n",tot);
	}
	return 0;
};