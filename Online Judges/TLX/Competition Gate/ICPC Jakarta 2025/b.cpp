#include <bits/stdc++.h>
#pragma GCC optimize("O3")

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
	int n;
	
	while(scanf("%d",&n) != EOF) {
		vi v(n);

		for(int i=0;i<n;i++){
			int num;
			scanf("%d",&num);
			v[i] = num;
		}

		vi ans(n, inf);
		int curTime = 0;
		for(int i=0;i<n;i++){
			curTime++;
			int calculated = min(curTime, v[i]);
			ans[i] = min(ans[i], calculated);
			curTime = calculated;
		}

		curTime = 0;
		for(int i=n-1;i>=0;i--){
			curTime++;
			int calculated = min(curTime, v[i]);
			ans[i] = min(ans[i], calculated);
			curTime = calculated;
		}

		int jawab = 0;
		for(int i=0;i<n;i++){
			jawab = max(jawab, ans[i]);
		}
		printf("%d\n", jawab);
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