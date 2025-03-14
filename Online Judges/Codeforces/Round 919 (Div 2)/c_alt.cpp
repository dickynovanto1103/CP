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

int a[200001];

vi getDivisors(int n) {
	vi divisors;
	for(int i=1;i*i<=n;i++){
		if(n%i == 0) {
			int div = n / i;
			if(i == div) {
				divisors.pb(i);
			}else{
				divisors.pb(i); divisors.pb(div);
			}
		}
	}
	return divisors;
}

void solve(){
	int n;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	vi divisors = getDivisors(n);

	int ans = 0;

	for(int k: divisors) {
		int gcd = 0;
		for(int i=0;i+k<n;i++){
			gcd = __gcd(gcd, abs(a[i] - a[i+k]));
		}


		if(gcd == 0 || gcd > 1) {ans++;}
	}

	printf("%d\n", ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};