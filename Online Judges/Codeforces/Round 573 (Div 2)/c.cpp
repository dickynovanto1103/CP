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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int m,i,j;
	ll n,k;
	scanf("%lld %d %lld",&n,&m,&k);
	ll kurang = 0;
	vi a;
	for(i=0;i<m;i++){
		ll bil;
		scanf("%lld",&bil);
		a.pb(bil);
	}
	// reverse(a.begin(), a.end());
	ll cnt = 0;
	ll idxAwal = 0;
	ll kelipatan, kaAsli = k;
	while(true) {
		if(idxAwal >= m){break;}
		if(a[idxAwal] > (kaAsli + kurang)){
			ll baru = a[idxAwal] - kurang;
			kelipatan = (baru+k-1) / k;
			kaAsli = kelipatan*k;
		}
		// printf("kaAsli: %lld kurang: %lld\n",kaAsli, kurang);
		
		ll idx = lower_bound(a.begin(), a.end(), kaAsli+kurang) - a.begin();
		// printf("idx: %lld\n",idx);
		if(idx == a.size()){
			idx--;
		}
		ll bil = a[idx];
		if(bil > kaAsli + kurang) {
			idx--;
			bil = a[idx];
		}
		cnt++;
		kurang += (idx-idxAwal+1);
		idxAwal = idx+1;
		// printf("idxAwal jd: %lld\n",idxAwal);
		if(idxAwal >= m){break;}
	}
	printf("%lld\n",cnt);
	return 0;
};