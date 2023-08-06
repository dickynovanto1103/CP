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
	int tc;
	scanf("%d",&tc);
	int a[200010];
	while(tc--){
		int n;
		scanf("%d",&n);
		ll sum = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}

		ll pref = 0;
		ll maks = 1;
		for(int i=0;i<(n-1);i++){
			pref += a[i];
			maks = max(maks, __gcd(pref, sum - pref));
		}

		printf("%lld\n", maks);
	}
	
	return 0;
};