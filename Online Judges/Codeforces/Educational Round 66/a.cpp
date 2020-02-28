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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	ll n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&k);
		ll ans = 0;
		while(n) {
			// printf("n: %lld\n",n);
			ll dekat = (n / k)*k;
			ll selisih = n - dekat;
			ans += selisih;
			n = dekat;
			while(n%k == 0 && n){
				n /= k;
				ans++;
			}
			// printf("n: %lld selisih: %lld\n",n,selisih);
		}
		printf("%lld\n", ans);
	}
	return 0;
};