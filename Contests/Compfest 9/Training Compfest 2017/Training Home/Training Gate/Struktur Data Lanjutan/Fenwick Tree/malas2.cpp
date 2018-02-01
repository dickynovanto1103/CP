#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll LSOne(ll a){return (a&(-a));}

class FenwickTree{
	private:
		vi ft;
	public:
		FenwickTree(int n){ft.assign(n+1,0);}
		ll rsq(int a){
			ll ans = 0;
			for(;a;a-=LSOne(a)){ans+=ft[a];}
			return ans;
		}
		ll rsq(int a, int b){
			return rsq(b) - rsq(a-1);
		}
		void update(int idx, ll value){
			for(;idx<ft.size();idx+=LSOne(idx)){ft[idx]+=value;}
		}
};

int main() {
	int n,m,i;
	ll a[100010];
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){scanf("%lld",&a[i]);}
	FenwickTree ft(n);
	for(i=1;i<=n;i++){ft.update(i,a[i]);}
	while(m--){
		int com, idx,l,r;
		ll k;
		scanf("%d",&com);
		if(com==1){
			scanf("%d %lld",&idx,&k);
			ll bil = a[idx]^k;
			ll selisih = bil-a[idx];
			a[idx] = bil;
			ft.update(idx,selisih);
		}
		else{
			scanf("%d %d",&l,&r);
			printf("%lld\n",ft.rsq(l,r));
		}
	}
	return 0;
}