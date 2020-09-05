#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000LL
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

const int maxn = 2e5 + 5;

ll banyakBuangKanan[maxn];
int smaller[maxn]; //untuk nyesuaiin dengan k
ll banyakBangunKiri[maxn];

int main(){
	int n,k,i,j;
	ll a[maxn];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	for(i=n-2;i>=0;i--){
		banyakBuangKanan[i] = banyakBuangKanan[i+1];
		if(a[i] != a[i+1]){
			ll banyakKanan = (n-1 - (i + 1) + 1);
			ll buang = banyakKanan * (ll)(a[i+1] - a[i]);
			banyakBuangKanan[i] += buang;
		}
	}
	int bil = a[0];
	for(i=1;i<n;i++){
		banyakBangunKiri[i] = banyakBangunKiri[i-1];
		smaller[i] = smaller[i-1];
		if(a[i] != a[i-1]) {
			smaller[i] = i;
			ll selisih = a[i] - a[i-1];
			banyakBangunKiri[i] += selisih * (ll)i;
		}
	}
	ll ans = (ll)inf*inf;
	for(i=0;i<n;i++){
		if(smaller[i] <= k) {
			ans = min(ans, banyakBangunKiri[i] + banyakBuangKanan[i]);
		}
	}
	assert(ans != (ll)inf*inf);
	printf("%lld\n",ans);
	return 0;
};