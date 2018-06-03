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

const int maxn = 1000002;
const ll mod = 1e9 + 7;
ll a[maxn], x[maxn], y[maxn];

ll modPow(ll a, ll b) {
	if(b==0){return 1;}
	else{
		if(b%2==1){return (a*modPow(a, b-1)) % mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp) % mod;
		}
	}
}

vector<vi> AdjList;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	AdjList.assign(102,vi());
	AdjList[1].pb(1);
	AdjList[2].pb(2); AdjList[2].pb(2);
	for(i=3;i<=100;i++){
		AdjList[i].pb(i);
		for(j=0;j<AdjList[i-2].size();j++){
			int bil = AdjList[i-2][j];
			AdjList[i].pb(bil+i);
		}
		AdjList[i].pb(i);
	}
	// for(i=1;i<=10;i++){
	// 	printf("node: %d:",i);
	// 	for(j=0;j<AdjList[i].size();j++){
	// 		printf(" %d", AdjList[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(int tt=1;tt<=tc;tt++) {
		printf("Case #%d: ",tt);
		ll n,k,x1,y1,c,d,e1,e2,f;
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&n,&k,&x1,&y1,&c,&d,&e1,&e2,&f);
		a[1] = (x1 + y1)%f;
		x[1] = x1; y[1] = y1;
		
		for(i=2;i<=n;i++){
			ll absis, ordinat;
			absis = ((c*x[i-1])%f + (d*y[i-1])%f + e1) % f;
			ordinat = ((d*x[i-1])%f + (c*y[i-1])%f + e2) % f;
			x[i] = absis; y[i] = ordinat;
			a[i] = (absis + ordinat) % f;
			// printf("a[%d]: %lld\n",i,a[i]);
		}

		ll sum = 0;
		// printf("n: %lld\n",n);
		// for(i=1;i<=k;i++){//hitung power i
		// 	for(j=0;j<AdjList[n].size();j++){
		// 		ll pengali = AdjList[n][j];
		// 		ll ans = (pengali*a[j+1]) % mod *modPow(j+1,i);
		// 		printf("j: %d pengali: %lld a[%d]: %lld modPow: %lld ans: %lld\n",j,pengali,j+1,a[j+1], modPow(j+1,i), ans);

		// 		sum+=ans;
		// 		sum%=mod;
		// 	}
		// 	printf("sum sementara: %lld\n",sum);
		// }
		for(int it = 1;it<=k;it++){
			
			for(i=1;i<=n;i++){
				ll jumlah = 0;
				int pangkat = 1;
				for(j=i;j<=n;j++){
					jumlah+=(a[j]*modPow(pangkat, it)) % mod;
					// printf("a[%d]: %lld pangkat: %d it: %d\n",j,a[j],pangkat,it);
					jumlah%=mod;
					// printf("jumlah: %lld\n",jumlah);
					pangkat++;
					sum+=jumlah;
					sum%=mod;
				}
				
			}
			
		}
		
		// for(j=0;j<AdjList[n].size();j++){
		// 	// printf("j: %d\n",j);
		// 	int bil = AdjList[n][j];
		// 	printf("bil: %d\n",bil);
		// 	for(i=1;i<=k;i++){
		// 		// printf("i: %d\n",i);
		// 		ll ans = ((bil*a[j+1])%mod*modPow(j+1,i)) % mod;
		// 		printf("pangkat %d dan %d\n",j+1,i);
		// 		// printf("ans: %lld\n",ans);
		// 		sum+=ans;
		// 		printf("ans: %lld\n",ans);
		// 		sum%=mod;
		// 	}
		// 	printf("sum sementara: %lld\n",sum);
		// }
		printf("%lld\n", sum);
	}
	return 0;
};