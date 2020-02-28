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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 998244353;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

int main(){
	int h,w;
	scanf("%d %d",&h,&w);
	ll ans = modPow(2,w);
	ans *= modPow(2,h);
	ans%=mod;
	// printf("ans: %lld\n",ans);
	// ans*=h;
	// ans%=mod;
	// ans*=2LL;
	// ans%=mod;
	printf("%lld\n",ans);
	return 0;
};