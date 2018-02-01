#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll modPow(ll a, ll b, ll c){
	if(b==0){return 1;}
	if(b%2==0){
		ll ans = (modPow(a,b/2,c)%c);
		return ((ans%c) * (ans%c))%c;
	}
	if(b%2==1){return ((a%c) * (modPow(a,b-1,c)%c))%c;}
}

int main() {
	int tc;
	ll x,y,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld %lld",&x,&y,&n);
		//printf("x: %lld y: %lld n: %lld\n",x,y,n);
		ll ans = modPow(x,y,n);
		printf("%lld\n",ans);
	}
	return 0;
}