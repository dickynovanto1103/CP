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

const ll mod = 1e9 + 7;

int main(){
	int tc,n,k,i,j;
	scanf("%d",&tc);
	ll a[10010];
	while(tc--){
		scanf("%d %d",&n,&k);

		
		ll sum = 0;

		for(i=1;i<=k;i++){
			sum += i;
			a[i] = i;
		}
		// printf("sum: %lld\n",sum);
		if(sum > n){printf("-1\n"); continue;}
		ll selisih = n-sum;
		ll penambahan = k;
		ll loop = selisih/penambahan;
		ll maksAngka = k + loop;
		ll total = sum + loop*penambahan;
		ll selisihSekarang = n - total;
		// printf("loop: %lld selisihSekarang: %lld\n",loop,selisihSekarang);
		for(i=k;i>=1;i--){
			a[i] = maksAngka;
			// printf("a[%d]: %lld\n",i,a[i]);
			maksAngka--;
		}
		for(i=k;i>=1;i--){
			if(selisihSekarang == 0){break;}
			a[i]++;
			// printf("sekarang a[%d]: %lld\n",i,a[i]);
			selisihSekarang--;
			
		}
		ll ans = 1;
		for(i=1;i<=k;i++){
			ll pengali = (((a[i]%mod)*(a[i]%mod))%mod - a[i]);
			if(pengali < 0){pengali += mod;}
			ans *= pengali;
			ans %= mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
};