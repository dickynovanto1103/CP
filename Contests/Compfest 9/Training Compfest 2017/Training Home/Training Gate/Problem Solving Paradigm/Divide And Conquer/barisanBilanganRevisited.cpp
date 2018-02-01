#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll gcd(ll a, ll b){return b==0? a:gcd(b,a%b);}
ll lcm(ll a, ll b){return a*(b/gcd(a,b));}

int main() {
	ll n,a,b,i;
	scanf("%lld %lld %lld",&n,&a,&b);
	ll kiri = 1, kanan = inf, mid;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		ll banyak = (mid/a) + (mid/b) - (mid/lcm(a,b));
		/*printf("a: %lld b: %lld lcm: %lld\n",a,b,lcm(a,b));
		printf("mid: %lld banyak: %lld\n",mid,banyak);*/
		if(banyak>n){kanan = mid-1;}//turunin range
		else if(banyak < n){kiri = mid+1;}
		else{break;}
	}
	for(i=mid;i>=0;i--){
		if(i%a==0 || i%b==0){break;}
	}
	printf("%lld\n",i);
	return 0;
}