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

int main(){
	int tc,i,j;
	ll n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&k);
		ll now = 1;
		ll need = 0;
		while(now <= k && now < n) {
			now *= 2LL;
			need++;
		}
		ll selisih = max(n - now, 0LL);

		need += (selisih + k - 1) / k;
		printf("%lld\n", need);
	}
	
	return 0;
};