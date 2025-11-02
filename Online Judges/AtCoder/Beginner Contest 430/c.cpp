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

void solve(){
	int n,a,b;
	while(scanf("%d%d%d",&n,&a,&b) != EOF) {
		// printf("halo n: %d a: %d b: %d\n", n, a, b);
		string s;
		cin>>s;
		int prefA[n + 1] = {0};
		int prefB[n + 1] = {0};
		for(int i=0;i<n;i++){
			if(s[i] == 'a'){
				prefA[i] = 1;
			}else{
				prefB[i] = 1;
			}
		}

		// cout<<s<<endl;
		for(int i=1;i<n;i++){
			prefA[i] += prefA[i-1];
			prefB[i] += prefB[i-1];
			// printf("prefA[%d]: %d b: %d\n", i, prefA[i], prefB[i]);
		}

		ll jawab = 0;

		for(int i=0;i<n;i++){
			//find first idx such that it's >= than A
			//abbaaabaaba
			// i = 0 -> 5, 5
			// i = 1 -> 
			int l = i, r = n-1, mid, ans1 = -1;
			// printf("processing i: %d\n", i);
			while(l <= r) {
				mid = (l + r) / 2;
				int cnt = prefA[mid] - (i == 0 ? 0 : prefA[i-1]);
				// printf("processing A mid: %d, cnt: %d\n", mid, cnt);
				if(cnt >= a){
					ans1 = mid;
					r = mid-1;
				}else{
					l = mid + 1;
				}
			}
			// printf("i: %d ans1: %d\n", i, ans1);

			//find first idx such that it's > B
			l = i, r = n-1;
			int ans2 = -1;
			while(l <= r) {
				mid = (l + r) / 2;
				int cnt = prefB[mid] - (i == 0 ? 0 : prefB[i-1]);
				// printf("processing B mid: %d, cnt: %d\n", mid, cnt);
				if(cnt < b) {
					ans2 = mid;
					l = mid + 1;
				}else{
					r = mid - 1;
				}
			}

			// printf("i: %d ans2: %d\n", i, ans2);

			if(ans1 == -1 || ans2 == -1) {
				continue;
			}

			jawab += max(0, ans2 - ans1 + 1);
		}

		printf("%lld\n", jawab);
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