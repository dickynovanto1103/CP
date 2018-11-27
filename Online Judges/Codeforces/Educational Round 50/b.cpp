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

ll tot;
ll gerak;
bool isPossible(ll x,ll y, ll k){
	gerak = min(x,y);
	x-=gerak;
	y-=gerak;
	tot = gerak + x+y;
	return tot <= k;
}

int main(){
	int q,i,j;
	ll n,m,k;
	scanf("%d",&q);
	while(q--){
		scanf("%lld %lld %lld",&n,&m,&k);
		tot = 0;
		gerak = 0;
		ll ans = 0;
		if(!isPossible(n,m,k)){
			printf("-1\n");
			continue;
		}else{
			ans += gerak;
			n-=gerak;
			m-=gerak;
			k-=gerak;
			ll total = n+m;
			// printf("total: %lld\n",total);
			if(total%2==1){
				ans += (total-1);
				k-=(total-1);
				k--;
				// printf("sisa k: %lld\n",k);
				ans += k;
			}else{
				ans += total;
				k-=total;
				if(k%2==1){
					k-=2;
				}
				ans+=k;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
};