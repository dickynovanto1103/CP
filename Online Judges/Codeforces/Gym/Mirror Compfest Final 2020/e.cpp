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

ll suffMinA[maxn];
ll suffSum[maxn];

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

		if(k == 0){
			ll sum = 0;
			ll ans = 0;
			for(i=n;i>=1;i--){
				sum += a[i];
				ans = max(ans, sum - d[i]);
			}
			printf("%lld\n",ans);
			continue;
		}

		ll ans = max(0LL, a[n] - d[n]);

		if(k == 1){
			//cuman skip satu
			//kasus dimana ak bs milih antara 1 .. n-1...ambil minimal d dan jumlahkan semua first n-1 a[i]
			ll minim = inf;
			ll sum = 0;
			for(i=1;i<=n-1;i++){
				minim = min(minim, d[i]);
				sum += a[i];
			}
			ans = max(ans, sum - minim);
			//kasus dimana ak cuman skip salah satu dari 2...n-1
			///buat kasus ini...ak harus iterasi...dan ditiap iterasi...assume that I start from this element...then I have to know all sum of a from this index to index n, then minus d[i] and min(a[i+1] .. a[N-1])
			suffMinA[n] = a[n];
			for(i=n-1;i>=1;i--){
				suffMinA[i] = min(a[i], suffMinA[i+1]);
			}
			suffSum[n] = a[n];
			for(i=n-1;i>=1;i--){
				suffSum[i] = a[i] + suffSum[i+1];
			}
			for(i=1;i<=n-2;i++) { //maks ak bs mulai skip cuman sampe n-2
				ll jawab = suffSum[i] - d[i] - suffMinA[i+1];
				ans = max(ans, jawab);
			}

			//coba skip 1
			for(i=2;i<=n;i++){
				ll jawab = suffSum[i] - d[i];
				ans = max(ans, jawab);
			}

		}else if(k % 2 == 0){
			//harusnya bs ambil semua
			ll minim = inf;
			ll sum = 0;
			for(i=1;i<=n;i++) {
				sum += a[i];
				if(i < n){ //karena kita ga bs mulai dari index n
					minim = min(minim, d[i]);
				}
			}
			ans = max(ans, sum - minim);
			
		}else {
			//k ganjil dan k > 1

			//ga bs ambil semua klo start dari index 2...harus salah coba salah satu diskip antara 1...n (kecuali 2 tentu saja) dan cari min(a[1], a[3..n])...
			//jawabannya adalah sum semua a - min(a[1], a[3..n]) - d[2]
			//assume klo mulai dari 2
			// ll jawab = 0;
			// ll minimum = inf;
			// ll jumlahSemua = 0;
			// for(i=1;i<=n;i++){
			// 	jumlahSemua += a[i];
			// 	if(i == 2){
			// 		continue;
			// 	}else{
			// 		minimum = min(minimum, a[i]);
			// 	}
			// }
			// ans = max(ans, jumlahSemua - minimum - d[2]);
			//selain itu..bs ambil semua
			ll minim = inf;
			ll sum = 0;
			for(i=1;i<=n;i++){
				sum += a[i];
				if(i < n){
					minim = min(minim, d[i]);
				}
			}
			ans = max(ans, sum - minim);
		}
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
};