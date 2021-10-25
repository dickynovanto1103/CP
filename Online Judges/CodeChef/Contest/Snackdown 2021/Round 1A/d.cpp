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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll f(vi v, int angka) {
	ll ans = 0;
	for(int i=0;i<v.size();i++){
		ans += abs(angka - v[i]);
	}
	return ans;
}

ll searchMin(vi v) {
	int n = v.size();
	assert(n > 0);
	int lo = v[0], hi = v[n-1], mid;
	ll ans = min(f(v, lo), f(v, hi));
	// printf("lo: %d hi: %d\n", lo, hi);
	while(hi > lo + 1) {
		// printf("sekarang, lo: %d hi: %d\n", lo, hi);
		mid = (lo + hi) / 2;
		ll ans1 = f(v, mid);
		ll ans2 = f(v, mid+1);
		// printf("mid: %d ans1: %lld ans2: %lld\n", mid, ans1, ans2);
		ans = min(ans, min(ans1, ans2));
		// printf("ans jd: %lld\n", ans);
		if(ans1 >= ans2) {
			lo = mid;
		}else{
			hi = mid;
		}
	}
	// printf("akhir ans: %lld\n", ans);

	return ans;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[100010];
	// ll pref[100010];
	while(tc--){
		scanf("%d", &n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		// fill(pref, pref+n, 0);
		// pref[0] = a[0];
		// for(i=1;i<n;i++){
		// 	pref[i] = a[i];
		// 	pref[i] += pref[i-1];
		// }

		if(n == 2) {puts("0"); continue;}
		if(n == 3) {
			int selisih1 = abs(a[0] - a[1]);
			int selisih2 = abs(a[1] - a[2]);
			printf("%d\n", min(selisih2, selisih1));
			continue;
		}

		ll ans = 1e18;
		//find tengah
		{
			int mid = (n-1)/2;
			
			for(int tt=mid-1;tt<=mid+1;tt++) {
				if(tt < 0 || tt >= n){continue;}
				ll cur = 0;
				for(i=0;i<n-1;i++){
					cur += abs(a[i] - a[tt]);
				}
				ans = min(ans, cur);
			}
		}
		{
			int mid = (n-1)/2;
			for(int tt=mid-1;tt<=mid+1;tt++) {
				if(tt < 0 || tt >= n){continue;}
				ll cur = 0;
				for(i=1;i<n;i++){
					cur += abs(a[i] - a[tt]);
				}
				ans = min(ans, cur);
			}
		}
		for(i=1;i<n-1;i++){
			ll selisih = a[i] - a[0];
			int target = a[n-1] - selisih;
			// printf("i: %d target: %d\n", i, target);
			if(i > 1 && i < n-2) {
				ans = min(ans, abs(selisih - (a[n-1] - a[i+1])));	
			}
			
			if(i == 1){continue;}
			int upper = upper_bound(a+1, a+i, target) - a;
			for(j=upper-30;j<=upper+30;j++) {
				if(j <= 0 || j >= (n-1)){continue;}
				if(j == i){continue;}
				ans = min(ans, abs(selisih - (a[n-1] - a[j])));	
			}
		}
		ll selisihAkhir = a[n-1] - a[0];
		ll selisihTengah = a[n-2] - a[1];
		ans = min(ans, abs(selisihAkhir - selisihTengah));
		printf("%lld\n", ans);
	}
	
	return 0;
};

/*
idx 1 dan terakhir pasti diambil
coba iterate ambil idx 1 dan x, lalu cari dari n, yang terdekat dengan jarak 
*/