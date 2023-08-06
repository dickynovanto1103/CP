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
		int a[600];
		int cnt[11];
		memset(cnt, 0, sizeof cnt);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			for(int j=0;j<10;j++) {
				if((1<<j) & a[i]) {
					cnt[j]++;
				}
			}
		}

		int ans = 0;
		for(int i=0;i<10;i++){
			if(cnt[i] > 0 && cnt[i] < n) {
				ans += (1<<i);
			}
		}

		printf("%d\n", ans);
	}
	
	return 0;
};