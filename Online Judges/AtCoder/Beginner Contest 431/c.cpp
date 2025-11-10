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
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k) != EOF) {
		int h[n + 1];
		int b[m + 1];
		for(int i=0;i<n;i++){
			scanf("%d",&h[i]);
		}

		sort(h, h + n);

		for(int i=0;i<m;i++){
			scanf("%d",&b[i]);
		}
		sort(b, b + );

		int cnt = 0;
		int idxHead = 0, idxBody = 0;
		while(idxHead < n && idxBody < m) {
			if(h[idxHead] > b[idxBody]) {
				idxBody++;
			}else{
				cnt++;
				idxHead++;
				idxBody++;
			}
		}

		if(cnt >= k){
			puts("Yes");
		}else{
			puts("No");
		}
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