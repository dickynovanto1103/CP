#include <bits/stdc++.h>

using namespace std;
#define inf 9e18
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int prime[]={2,3,5};

bool isFactorOf2and3(ll n){
	ll idx = 0, pf = prime[idx];
	while(pf*pf<=n && idx<2){
		while(n%pf==0){n/=pf;}
		pf = prime[++idx];
	}
	if(n!=1){
		if(n!=2 || n!=3){return false;}
		else{return true;}
	}
}

int main() {
	ll n,i;
	vi a;
	for(i=0;i<=31;i++){
		a.pb(1LL<<i);
	}
	for(i=0;i<31;i++){
		int cnt = 0;
		ll kali = (ll)pow(3,cnt);
		while((1LL<<i)*kali <= (1LL<<31LL)){
			a.pb((1LL<<i) * kali);
			cnt++;
			kali = (ll)pow(3,cnt);
		}
	}
	int ukuran = a.size();
	sort(a.begin(),a.end());
	
	while(scanf("%lld",&n),n){
		int idx = lower_bound(a.begin(),a.end(),n) - a.begin();
		printf("%lld\n",a[idx]);
	}
	return 0;
}