#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 4;
ll a[maxn], b[maxn], c[maxn];
ll aKecil[maxn], bKecil[maxn];

int main(){
	int tc;
	int n,m,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=0;i<maxn;i++){aKecil[i] = bKecil[i] = inf;}
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		for(i=0;i<n;i++){scanf("%lld",&b[i]);}
		for(i=0;i<m;i++){scanf("%lld",&c[i]);}
		ll mod = m;
		//lalu iterasi dari a sama b
		for(i=0;i<n;i++){
			int hasilMod = a[i]%mod;
			aKecil[hasilMod] = min(aKecil[hasilMod], a[i]);
			hasilMod = b[i]%mod;
			bKecil[hasilMod] = min(bKecil[hasilMod], b[i]);
		}
		//list bil A Kecil dan B kecil
		vi listAKecil, listBKecil;
		for(i=0;i<m;i++){
			if(aKecil[i]!=inf){listAKecil.pb(aKecil[i]);}
			if(bKecil[i]!=inf){listBKecil.pb(bKecil[i]);}
		}
		sort(listAKecil.begin(), listAKecil.end());
		sort(listBKecil.begin(), listBKecil.end());
		int ukuranA = listAKecil.size(), ukuranB = listBKecil.size();
		ll ans = inf;
		for(i=0;i<ukuranA;i++){
			ll bil1 = listAKecil[i];
			for(j=0;j<ukuranB;j++){
				ll bil2 = listBKecil[j];
				ll cur = bil1*bil2;
				if(cur>=ans){break;}
				cur+=c[(bil1*bil2)%mod];
				ans = min(ans,cur);
			}
		}
		printf("%lld\n",ans);
	}
	

	return 0;
};