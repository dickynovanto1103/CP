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

const int maxn = 110;
const ll mod = 1000000007LL;

ll modPow(ll a, ll b) {
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return ((a%mod)*(modPow(a,b-1)%mod))%mod;
		}else{
			ll temp = modPow(a,b/2)%mod;
			return (temp*temp)%mod;
		}
	}
}

ll compute(ll a, ll b){
	ll ans = (modPow(a,b)-1);
	if(ans<0){ans+=mod;}
	return (ans%mod * (modPow(a-1,1000000005))%mod)%mod;

}

int main(){
	int tc,n,i;
	ll a[maxn], b[maxn], c[maxn];
	// ll ans = 14*108*6;
	// printf("%lld\n",ans);
	scanf("%d",&tc);

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);}
		ll ans = 1;
		for(i=0;i<n;i++){
			if(a[i]==1){ans*=(c[i]-b[i]+1); ans%=mod; continue;}
			ll ans1 = compute(a[i],c[i]+1);
			ll ans2 = compute(a[i],b[i]);
			ll jawab = ans1-ans2;
			if(jawab<0){jawab+=mod;}
			ans*=(jawab);

			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
};