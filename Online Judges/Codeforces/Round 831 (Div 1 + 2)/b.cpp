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
	while(tc--){
		int n;
		scanf("%d",&n);
		

		int maxTall = 0;
		ll sumSmall = 0;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			
			if(a < b) swap(a, b);
			maxTall = max(maxTall, a);
			sumSmall += b;
		}
		ll ans = 2LL * sumSmall + 2LL * maxTall;
		printf("%lld\n", ans);
	}
	
	return 0;
};