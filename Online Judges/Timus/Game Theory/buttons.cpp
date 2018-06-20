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
	ll n;
	

	scanf("%lld",&n);
	for(ll i=3;i*2LL<=n;i++){
		if(n%i==0){
			printf("%lld\n",i-1);
			return 0;
		}
	}
	printf("%lld\n",n-1);
	return 0;
};