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

bool isPrime[20010];

void genPrime(int n) {
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i*i<=n;i++){
		for(int j=i*i;j<=n;j+=i){
			isPrime[j] = false;
		}
	}
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[101];
	memset(isPrime, true, sizeof isPrime);
	genPrime(20000);
	
	while(tc--){
		scanf("%d",&n);
		vi ans;
		vi ganjil;
		vi genap;
		int sum = 0;
		int sumAns = 0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
			if(a[i] % 2 == 0 && a[i] > 2){
				ans.pb(i);
				sumAns += a[i];
			}else if(a[i] == 2){
				genap.pb(i);
			}else if(a[i] % 2 == 1){
				ganjil.pb(i);
			}
		}

		if(!isPrime[sum]) {
			printf("%d\n", n);
			for(i=1;i<=n;i++){
				printf("%d ", i);
			}
			puts("");
			continue;
		}

		int szGanjil = ganjil.size();
		if(szGanjil % 2 == 1){szGanjil--;}
		while(szGanjil--){
			int back = ganjil.back(); ganjil.pop_back();
			ans.pb(back);
			sumAns += a[back];
		}

		// printf("sum ans: %d ans size: %d\n", sumAns, ans.size());
		if(genap.size() >= 1) {
			if(!isPrime[sumAns + 2]) {
				sumAns += 2;
				ans.pb(genap[0]);
			}
		}

		if(ganjil.size() >= 1) {
			if(!isPrime[sumAns + a[ganjil[0]]]) {
				sumAns += a[ganjil[0]];
				ans.pb(ganjil[0]);
			}
		}

		printf("%d\n", ans.size());
		for(int x: ans){
			printf("%d ", x);
		}
		puts("");
	}
	
	return 0;
};