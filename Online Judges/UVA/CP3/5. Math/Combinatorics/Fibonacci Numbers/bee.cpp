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
	ll fib[110],fib1[110];
	int i,n;
	fib[0] = 0; fib1[0] = 1;
	fib[1] = 1; fib1[1] = 2;
	for(i=2;i<110;i++){
		fib[i] = fib[i-1] + fib[i-2] + 1;
		fib1[i] = fib1[i-1] + fib1[i-2] + 1;
	}
	while(scanf("%d",&n),(n!=-1)){

		printf("%lld %lld\n",fib[n],fib1[n]);
	}
	return 0;
}