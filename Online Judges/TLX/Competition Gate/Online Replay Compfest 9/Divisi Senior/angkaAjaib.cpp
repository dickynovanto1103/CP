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

const ll mod = 1e9 + 7;
ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){return ((a%mod)*(modPow(a,b-1)%mod))%mod;}
		else{
			ll temp = modPow(a,b/2);
			return ((temp%mod) * (temp%mod))%mod;
		}
	}
}

int main(){
	int tc,n,k;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		cin>>kata;
		ll banyak1 = modPow(10LL,(ll)n)%mod;
		ll sisaDigit = n-k;
		ll banyakPengulangan = (n - k + 1);
		ll banyak2 = ((banyakPengulangan%mod)*(modPow(10LL,sisaDigit)%mod))%mod;
		ll ans = (banyak1 - banyak2)%mod;
		if(ans<0){ans+=mod; ans%=mod;}
		
		// for(ll i=0;i<banyakPengulangan;i++){

		// }
		// ll banyak2 = ((banyakPengulangan%mod)*(modPow(10LL,sisaDigit)%mod))%mod;
		// ll ans = banyak1-banyak2;
		// if(ans<0){ans+=mod;}
		//printf("banyak1: %lld banyak2: %lld\n",banyak1,banyak2);
		printf("%lld\n",ans);
	}
	return 0;
};