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

const ll mod = 1e9 + 7;
ll power[10001];

//idea: compute how many times this number will be max and how many times this number will be min
int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int a[10001];
	power[0] = 1;
	for(i=1;i<=10000;i++){
		power[i] = power[i-1] * 2LL;
		power[i] %= mod;
	}
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		ll sum = 0;
		for(i=0;i<n;i++){
			ll banyakLebihKecil = i;
			sum += (ll)a[i] * (banyakLebihKecil <= 0 ? 0 : (power[banyakLebihKecil] - 1));
			sum %= mod;

			ll banyakLebihBesar = n - i - 1;
			sum -= (ll)a[i] * (banyakLebihBesar <= 0 ? 0 : (power[banyakLebihBesar] - 1));
			sum %= mod;
			if(sum < 0) {
				sum += mod;
			}
		}
		// for(i=0;i<n;i++){
		// 	for(j=i+1;j<n;j++){
		// 		ll selisih = a[j] - a[i];
		// 		ll sisa = (j - i + 1 - 2);
		// 		assert(sisa >= 0);
		// 		sum += selisih * power[sisa];
		// 		sum %= mod;
		// 	}
		// }
		printf("%lld\n", sum);
	}
	
	return 0;
};