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

ll tenPower[10];

int main(){
	int tc,i,j,n,k;

	tenPower[0] = 1;
	for(i=1;i<10;i++){
		tenPower[i] = tenPower[i-1] * 10LL;
	}


	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		int a[11];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		k++;
		ll ans = 0;
		for(i=0;i<n;i++){
			int next = -1;
			if(i < (n-1)) {
				next = 1;
				for(j=0;j<a[i+1];j++){
					next *= 10;
				}
			}

			if(next == -1) {
				ans += (k * tenPower[a[i]]);
			}else{
				int selisih = a[i+1] - a[i];
				ll banyak = min(tenPower[selisih] - 1, (ll)k);
				ans += (tenPower[a[i]] * banyak);
				k -= banyak;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
};