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

const int maxn = 1e3 + 3;
const ll mod = 998244353;

ll dp[maxn];
ll comb[maxn][maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		for(j=0;j<=i;j++){
			if(j==0 || j==i){comb[i][j] = 1;}
			else{comb[i][j] = ((comb[i-1][j-1]%mod) + (comb[i-1][j]%mod))%mod;}
		}
	}

	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	dp[n] = 1;
	for(i=n-1;i>=0;i--){
		int bil = a[i];
		if(bil <= 0){dp[i] = 0; continue;}
		
		int idxSelanjutnya = i+bil+1;
		if(idxSelanjutnya > n){dp[i] = 0; continue;}

		ll ans = 0;
		// printf("i: %d\n",i);
		
		for(j=idxSelanjutnya;j<=n;j++){
			int banyakDiantara = j-i-1;
			int banyakAmbil = bil;
			// printf("banyakDiantara: %d banyakAmbil: %d\n",banyakDiantara, banyakAmbil);
			ll banyakKombinasiSebelum = comb[banyakDiantara][banyakAmbil];
			
			ll total = ((dp[j]%mod)*(banyakKombinasiSebelum%mod))%mod;
			// total+=banyakKombinasiSebelum;
			// total%=mod;
			// printf("j: %d banyakKombinasiSebelum: %lld dp[%d]: %lld total: %lld\n",j,banyakKombinasiSebelum,j,dp[j], total);
			ans += total;
			// printf("ans jd: %lld\n", ans);
			ans%=mod;
		}

		dp[i] = ans;
		// printf("dp[%d]: %lld\n",i,dp[i]);
	}

	ll jawab = 0;
	for(i=0;i<n;i++){
		jawab+=dp[i];
		jawab%=mod;
	}

	printf("%lld\n",jawab);

	return 0;
};