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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

ll modPow(ll a, ll b) {
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a * modPow(a, b-1) % mod;}
		else{
			ll temp = modPow(a, b/2);
			return temp*temp % mod;
		}
	}
}

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		ll ans = 0;
		for(i=0;i<31;i++){
			if((1<<i) & k) {
				ans += modPow(n, i);
				if(ans >= mod) {
					ans -= mod;
				}
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
};