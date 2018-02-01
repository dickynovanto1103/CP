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
typedef multiset<ll>::iterator It;
const int maxn = 4000;
ll counter[maxn*maxn];
unordered_map<int, int> s;
pair<It, It> it;

int main(){
	int n,i,j;
	int a[maxn], b[maxn], c[maxn], d[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	// bikin multiset
	s.reserve(maxn*maxn);
	ll idx = 1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			//s.insert(c[i] + d[j]);
			if(s[c[i] + d[j]]==0){
				s[c[i] + d[j]] = idx;
				counter[idx]++;
				idx++;
			}else{
				ll indeks = s[c[i] + d[j]];
				counter[indeks]++;
			}
		}
	}
	
	ll ans = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			ll bil = a[i] + b[j];
			ll cari = -(bil);
			// it = s.equal_range(cari);
			// ll idxAkhir = (ll)distance(s.begin(), it.second);
			// ll idxAwal = (ll)distance(s.begin(), it.first);
			if(s.find(cari)!=s.end()){
				ll indeks = s[cari];
				ans+=(counter[indeks]);	
			}
			
		}
	}
	printf("%lld\n",ans);
	return 0;
};