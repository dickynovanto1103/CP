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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

int main(){
	int n,i,j;
	ll x,y;
	scanf("%d %lld %lld",&n,&x,&y);
	ii a[maxn];
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].first,&a[i].second);
	}

	multiset<int>::iterator it;
	multiset<ii> listSegment;
	multiset<ii>::iterator it2;
	sort(a,a+n);

	for(i=0;i<n;i++){
		int awal = a[i].first, akhir = a[i].second;

		it2 = listSegment.lower_bound(ii(awal,0));
		
		if(it2 == listSegment.begin()){
			listSegment.insert(ii(akhir,awal));
		}else{
			it2--;
			ii elemen = *it2;

			ll cost = (ll)(awal - elemen.first)*y;
			if(cost > x){//sewa tv baru
				listSegment.insert(ii(akhir,awal));
			}else{
				int beginAwal = elemen.second;

				listSegment.erase(it2);
				
				listSegment.insert(ii(akhir, beginAwal));
			}
		}
		
	}
	ll ans = 0;

	for(it2=listSegment.begin();it2!=listSegment.end();it2++){
		ii pas = *it2;
		ll selisih = pas.first - pas.second;
		
		ans += selisih*y;
		ans %= mod;
		ans += x;
		ans %= mod;
	}
	printf("%lld\n",ans);
	return 0;
};