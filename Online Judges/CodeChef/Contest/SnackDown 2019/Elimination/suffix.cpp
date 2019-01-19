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

ll mod;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2==1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

int main(){
	int n,s,i,j;
	
	scanf("%d %d %lld",&n,&s,&mod);
	ll ans = modPow(s,n);
	printf("ans awal: %lld\n",ans);
	for(i=2;i<=n;i++){
		ll jawab = modPow(s,n-i)*modPow(s,(i+1)/2);
		printf("i: %d jawab: %lld\n",i,jawab);
		jawab %= mod;
		
		if(i%2==0){

			ans -= jawab;
		}else{
			ans += jawab;
		}
		ans %= mod;
		if(ans < 0){ans += mod;}
		printf("ans jd: %lld\n",ans);
	}
	if(ans < 0){ans += mod;}
	printf("%lld\n",ans);
	return 0;
};