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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

ll pref[maxn];

ll hit(int awal, int akhir) {
	return pref[akhir] - (awal == 0 ? 0 : pref[awal-1]);
}

int main(){
	int tc,i,j;
	int n;
	ll x;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %lld",&n,&x);
		ll a[maxn];
		
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			pref[i] = a[i];
			if(i){pref[i] += pref[i-1];}
		}
		ll jawab = 0;
		for(i=0;i<n;i++){
			int kiri = i, kanan = n-1, mid, ans = -1;
			while(kiri <= kanan) {
				mid = (kiri + kanan) / 2;
				ll tot = hit(i, mid);
				if(tot < x) {
					ans = mid;
					kiri = mid+1;
				}else{
					kanan = mid-1;
				}
			}
			if(ans == -1){continue;}
			else{
				jawab += (ans - i + 1);
			}
		}
		printf("%lld\n",jawab);
	}
	return 0;
};