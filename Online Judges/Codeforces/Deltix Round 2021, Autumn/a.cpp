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
	int tc,i,j,n;
	scanf("%d",&tc);
	ll a[16];
	while(tc--){
		scanf("%d",&n);
		int cnt = 0;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			while(a[i] % 2 == 0) {
				a[i] /= 2;
				cnt++;
			}
		}

		sort(a, a+n);
		for(i=0;i<cnt;i++){
			a[n-1] *= 2LL;
		}

		ll sum = 0;
		for(i=0;i<n;i++){
			sum += a[i];
		}
		printf("%lld\n", sum);
	}
	
	return 0;
};