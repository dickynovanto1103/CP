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

const int maxn = 2e6 + 10;
const int mod = 998244353;
int pangkat1[maxn];
int pangkat2[maxn];

int a[100010];
int c[100010];

void solve(){
	int n,m;
	while(scanf("%d",&n) != EOF) {
		memset(pangkat1, 0, sizeof pangkat1);
		memset(pangkat2, 0, sizeof pangkat2);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		for(int i=0;i<n;i++){
			int pangkat;
			scanf("%d",&pangkat);
			pangkat1[a[i]] = pangkat;
		}

		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&c[i]);
		}

		ll ans = 1;
		for(int i=0;i<m;i++){
			int pangkat;
			scanf("%d",&pangkat);
			pangkat2[c[i]] = pangkat;
			if(pangkat1[c[i]] < pangkat2[c[i]]) {
				ans = 0;
			}
		}

		if(ans == 0) {puts("0"); continue;}
		ans = 1;
		for(int i=0;i<n;i++){
			if(pangkat2[a[i]] != pangkat1[a[i]]) {
				ans *= 2LL;
				ans %= mod;
			}
		}
		
		printf("%lld\n", ans);
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};