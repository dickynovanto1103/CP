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

int a[100010];
int b[100010];

void validate(int n) {
	ll sum = 0;
	ll sumAbsB = 0;
	for(int i=0;i<n;i++){
		// printf("a[%d]: %d b: %d\n", i, a[i], b[i]);
		assert(b[i] != 0);
		sumAbsB += abs(b[i]);
		sum += (ll)a[i] * b[i];
	}
	assert(sum == 0);
	assert(sumAbsB <= inf);
}

ll pref[100010];
//another approach: instead of using the direct number of a[i], use this formula
// sum of all numbers except a[i] = s
// s * x % a[i] = 0, find smallest x possible
//it means x = a[i] / gcd(a[i], s)
// 

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			pref[i] = a[i];
			if(i) pref[i] += pref[i-1];
		}

		for(i=0;i<n;i++) {
			ll kiri = pref[i] - a[i];
			ll kanan = pref[n-1] - pref[i];
			ll sum = kiri + kanan;
			if(sum == 0){continue;}
			ll gcd = __gcd((ll)abs(a[i]), abs(sum));
			ll x = (ll)abs(a[i]) / gcd;
			// printf("a[%d]: %d sum: %lld gcd: %lld x: %lld\n", i, a[i], sum, gcd, x);
			ll newSum = x * sum;
			
			b[i] = -1LL * (newSum) / a[i];
			// printf("newSum: %lld b: %d\n", newSum, b[i]);
			if((b[i] + (ll)abs(x) * (n-1)) > inf) {continue;}

			for(j=0;j<n;j++){
				if(j == i){continue;}
				b[j] = abs(x);
			}

			break;
		}

		validate(n);
		for(i=0;i<n;i++){
			printf("%d ", b[i]);
		}
		puts("");
	}
	
	return 0;
};