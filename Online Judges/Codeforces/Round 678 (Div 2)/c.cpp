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
typedef vector<ii> vii;

vi travel(int tujuan, int n){
	vi ans;
	int kiri = 0, kanan = n;
	while(kiri < kanan){
		int mid = (kiri + kanan)/2;
		ans.pb(mid);
		if(mid <= tujuan){
			kiri = mid+1;
		}else{
			kanan = mid;
		}
	}
	return ans;
}

const ll mod = 1e9 + 7;

ll fac[1010];

int main(){
	int n,x,pos,i,j;
	fac[0] = fac[1] = 1;
	for(i=2;i<=1010;i++){
		fac[i] = (ll)i*fac[i-1];
		fac[i] %= mod;
	}
	while(scanf("%d %d %d",&n,&x,&pos) !=EOF){
		vi v = travel(pos, n);
		int kecil = 0, besar = 0;
		for(i=1;i<=n;i++){
			if(i < x){
				kecil++;
			}else if(i > x){
				besar++;
			}
		}
		ll ans = 1;
		n--;
		for(i=0;i<v.size();i++){
			int idx = v[i];
			// printf("idx: %d pos: %d n: %d\n",idx, pos, n);
			if(idx < pos){
				//berarti dia lebih kecil dari x
				ans *= kecil; ans %= mod;
				kecil--;
				n--;
			}else if(idx > pos){
				ans *= besar;
				besar--;
				ans %= mod;
				n--;
			}
			// printf("ans: %lld\n",ans);
		}
		// printf("n: %d fac[%d]: %lld\n",n, n, fac[n]);
		ans *= fac[n];
		// printf("ans skrg: %lld\n",ans);
		ans %= mod;
		// printf("n: %d ans: %lld\n",n, ans);
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
};