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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll m;

ll findMax(const vi& a){
	int n = a.size(),i,j;
	printf("n: %d\n",n);
	ll ans = -inf;
	printf("listbil:");
	for(i=0;i<n;i++){
		printf(" %d",a[i]);
	}
	printf("\n");
	for(i=0;i<(1<<n);i++){
		ll sum = 0;
		for(j=0;j<n;j++){
			if(i&(1<<j)){
				sum+=(a[j]%m);
				printf("sum ditambahin %d jd: %d\n",a[j],sum);
			}
		}
		if(ans < sum){ans = sum;}
	}
	printf("ans: %d\n",ans);
	return ans;
}

int main(){
	int n,i,j;
	ll a[40];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	int tengah = n/2;
	vi bilPertama, bilTerakhir;
	printf("tengah: %d\n",tengah);
	for(i=0;i<tengah;i++){
		bilPertama.pb(a[i]);

	}
	for(i=tengah;i<n;i++){
		bilTerakhir.pb(a[i]);
	}
	ll sum = 0;
	sum = sum + (findMax(bilPertama) % m);
	sum = (sum%m + (findMax(bilTerakhir) % m))%m ;
	printf("%lld\n",sum);

	return 0;
};