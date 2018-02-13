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
	int tc,i,j;
	ll a,b;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&a,&b);
		ll gcd = __gcd(a,b);
		ll lcm = a*(b/gcd);
		if(gcd==a && lcm==b){
			printf("%lld %lld\n",a,b);
		}else{
			printf("-1\n");
		}
	}
	
	return 0;
};