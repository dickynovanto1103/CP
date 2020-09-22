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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ii> iii;
typedef vector<ii> vii;

ll n,m;

ll cntNumSmaller(ll mid) {
	// printf("mid sekarang: %lld\n",mid);
	ll banyak = 0;
	ll i,j;
	for(i=1;i<=n;i++){
		ll bagi = mid / i;
		if(mid % i == 0){
			bagi--;
		}	
		bagi = min(bagi, m);
		banyak += bagi;
	}
	
	// printf("banyakTotal: %lld\n", banyak);
	return banyak;
}

int main(){
	int i,j;
	ll k;
	scanf("%lld %lld %lld",&n,&m,&k);
	// for(i=1;i<=n;i++){
	// 	for(j=1;j<=n;j++){
	// 		printf("%3d",i*j);
	// 	}
	// 	printf("\n");
	// }
	ll kiri = 1, kanan = n*m, mid, ans;
	while(kiri <= kanan){
		mid = (kiri + kanan)/2LL;
		ll cntSmaller = cntNumSmaller(mid);
		// printf("mid: %lld cntSmaller: %lld\n",mid, cntSmaller);
		if(cntSmaller < k){
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
};