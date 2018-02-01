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
	int tc;
	ll n;
	ll fib[110];
	set<ll> s;
	fib[0] = 0; fib[1] = 1;
	s.insert(0); s.insert(1);
	for(int i=2;;i++){
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i]>10000000000LL){break;}
		s.insert(fib[i]);
	}
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&n);
		if(s.count(n)){printf("IsFibo\n");}
		else{printf("IsNotFibo\n");}
	}
	return 0;
};