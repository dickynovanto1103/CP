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
	ll n,m;
	scanf("%lld %lld",&n,&m);
	if(n==1 || m==1){
		if(n==1){
			printf("%lld\n",m);
		}else{
			printf("%lld\n",n);
		}
		return 0;
	}
	if(n==2 && m==2){
		printf("4\n");
		return 0;
	}

	if(n==2 || m==2){
		ll jawab = n+m;
		
		printf("%lld\n",jawab);
		return 0;
	}
	ll jawab = n+m;
	printf("%lld\n",jawab);
	return 0;
};