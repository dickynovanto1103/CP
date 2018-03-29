#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000
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

const int maxn = 1e6 + 6;

ll a[maxn];

int main(){
	int i,j;
	ll m,n;
	scanf("%lld %lld",&n,&m);
	ll minim = inf, maks = -inf;
	for(i=0;i<n;i++) {
		scanf("%lld",&a[i]);
		minim = min(minim,a[i]); maks = max(maks, a[i]);
	}
	ll kiri = 0, kanan = maks;
	ll ans;
	while(kiri<=kanan) {
		ll mid = (kiri+kanan)/2;
		ll totalTerpotong = 0;
		for(i=0;i<n;i++){
			if(a[i] > mid){
				totalTerpotong+=(a[i] - mid);
			}
		}
		if(totalTerpotong >= m) {
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	printf("%lld\n",ans);

	return 0;
};