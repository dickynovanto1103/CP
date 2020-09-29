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

const int maxn = 1e5 + 5;

ll prefSumA[maxn];
ll suffSum[maxn];
ll suffMax[maxn];
ll minimD[maxn];

int main(){
	int n,k,i,j;
	ll a[maxn], d[maxn];
	while(scanf("%d %d",&n,&k) != EOF){
		// printf("n: %d k: %d\n",n, k);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&d[i]);
		}
		//process suffix
		ll sum = a[n];
		suffMax[n] = max(0LL, a[n] - d[n]);
		suffSum[n] = a[n];
		for(i=n-1;i>=1;i--) {
			sum += a[i];
			suffSum[i] = sum;
			suffMax[i] = max(suffMax[i+1], sum - d[i]);
		}
		prefSumA[1] = a[1];
		minimD[1] = d[1];
		for(i=2;i<=n;i++){
			prefSumA[i] = a[i] + prefSumA[i-1];
			// printf("prefSumA[%d]: %lld\n",i, prefSumA[i]);
			minimD[i] = min(minimD[i-1], d[i]);
		}

		if(k == 0){
			printf("%lld\n",suffMax[1]);
			continue;
		}

		ll ans = max(0LL, a[n] - d[n]);

		if(k == 1){
			//kasus dimana ak cuman skip salah satu dari 2...n-1
			//
			///buat kasus ini...ak harus iterasi...dan ditiap iterasi...assume that I start from this element...then I have to know all sum of a from this index to index n, then minus d[i] and min(a[i+1] .. a[N-1])
			ll maksVal = -inf;
			for(i=2;i<=n-1;i++){
				//mulai excite atom dari sebelum i
				maksVal = max(maksVal + a[i-1], a[i-1] - d[i-1]);
				ans = max(ans, maksVal + suffSum[i+1] + (a[i] > d[i] ? a[i] - d[i] : 0));
				//mulai excite atom dari setelah i
				ans = max(ans, suffMax[i+1]);
			}

			//coba skip 1
			for(i=2;i<=n;i++){
				ll jawab = suffSum[i] - d[i];
				ans = max(ans, jawab);
			}

			//kasus dimana membentuk back edge (dari i ke 1, 2 <= i <= n-1)...untuk kasus ini, cukup hitung min(d[1]...d[i]) dan prefSumA[i]...lalu tambahkan dengan suffMax[i+1] (karena bs excite lebih dari 1 kali)
			//ga perlu memperhitungkan kasus dimana dari i ke j, j < i, karena i ke i sudah pasti lebih optimal karena bs memilih pemilihan optimal dari i kemungkinan
			//IMPLEMENT
			for(i=2;i<=n-1;i++){
				// printf("prefSumA[%d]: %lld minimD: %lld suffMax[%d]: %lld\n", i, prefSumA[i], minimD[i], i+1, suffMax[i+1]);
				ans = max(ans, prefSumA[i] - minimD[i] + suffMax[i+1]);
			}

		}else {
			//bs ambil semua untuk kasus k > 1
			ll minim = inf;
			ll sum = 0;
			for(i=1;i<=n;i++){
				sum += a[i];
				if(i < n){
					minim = min(minim, d[i]);
				}
			}
			// printf("sum: %lld minim: %lld\n",sum, minim);
			ans = max(ans, sum - minim);
		}
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
};