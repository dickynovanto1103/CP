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

const int maxn = 150010;

int main() {
	ll fib[maxn];
	int a,b,n,m,i;
	int batas, mod=100;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d",&a,&b,&n,&m);
		fib[0] = a, fib[1] = b;
		//for(i=2;i<=1000;i++){fib[i] = (fib[i-1]%mod + fib[i-2]%mod)%mod;}
		//for(i=0;i<=1000;i++){printf("i: %d fib: %d\n",i,fib[i]);}
		
		if(m==1){batas=60; mod = 10;}
		else if(m==2){batas=300; mod = 100;}
		else if(m==3){batas = 1500; mod = 1000;}
		else if(m==4){batas = 15000; mod = 10000;}
		
		mod = 1000000;
		for(i=2;i<=batas+10;i++){
			fib[i] = (fib[i-1]%mod + fib[i-2]%mod)%mod;
		}
		mod = (int)pow(10,m);
		int idx = n;
		if(n>batas){idx=n%batas;}

		printf("%lld\n",fib[idx]%mod);
	}
	
	
	return 0;
}