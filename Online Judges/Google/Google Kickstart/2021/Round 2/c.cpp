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

vi getResult(vi a) {
	int sz = a.size();
	vi ans;
	ans.pb(1);
	for(int i=1;i<sz;i++){
		int seen = 1;
		int maks = a[i];
		for(int j=i-1;j>=0;j--) {
			if(a[j] > maks) {
				seen++;
				maks = a[j];
			}
		}
		ans.pb(seen);
	}
	return ans;
}

int main(){
	int tc,i,j,n;
	scanf("%d", &tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d",&n);
		int a[20];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		vi v;
		for(i=0;i<n;i++){
			v.pb(i+1);
		}

		ll ans = 0;
		do {
			// for(i=0;i<n;i++){
			// 	printf("%d ", v[i]);
			// }
			// printf("\n");
			vi res = getResult(v);
			// printf("result\n");
			// for(i=0;i<n;i++){
			// 	printf("%d ", res[i]);
			// }
			// printf("\n");
			assert(res.size() == n);
			bool valid = true;
			for(int i=0;i<n;i++){
				if(res[i] != a[i]) {
					valid = false;
					break;
				}
			}
			if(valid){
				ans++;
			}
		}while(next_permutation(v.begin(), v.end()));
		printf("%lld\n", ans);
	}
	
	return 0;
};