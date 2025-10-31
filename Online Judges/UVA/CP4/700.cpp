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
	int n;
	int tt = 1;
	while(scanf("%d",&n), n) {
		printf("Case #%d:\n", tt++);
		unordered_map<int, int> cnt;
		set<int> s;
		set<int>::iterator it;

		for(int i=0;i<n;i++){
			int year, min, max;
			scanf("%d%d%d",&year,&min,&max);
			for(int j=year;j<10000;j+=(max-min)) {
				s.insert(j);
				cnt[j]++;
			}
		}

		int ans = -1;
		for(it=s.begin();it!=s.end();it++){
			if(cnt[*it] == n){
				ans = *it;
				break;
			}
		}

		if(ans == -1) {
			puts("Unknown bugs detected.");
		}else{
			printf("The actual year is %d.\n", ans);
		}
		puts("");
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