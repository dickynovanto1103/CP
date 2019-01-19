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

int main(){
	int tc,i,j,k;
	ll n,p;

	scanf("%d",&tc);

	while(tc--){
		scanf("%lld %lld",&n,&p);
		ll bagiTerbesar = n/2LL + 1LL;
		ll maks = n % bagiTerbesar;
		ll selisih = p-maks;
		ll jarak = p-bagiTerbesar-1;
		// printf("selisih: %lld\n",selisih);
		ll ans = 0;
		if(n == 2 || n == 1){
			ans = p*p*p;
		}else{
			ans += selisih*selisih;
			ans += (p-n)*selisih;
			ans += (p-n)*(p-n);
		}
		printf("%lld\n",ans);
	}
	

	return 0;
};