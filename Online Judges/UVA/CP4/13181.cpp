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

char s[500010];

void solve(){

	while(scanf("%s",s) != EOF) {
		int n = strlen(s);
		vector<ii> distToX(n);
		distToX.assign(n, ii(inf,inf));

		int idxX = -1;
		for(int i=0;i<n;i++){
			if(s[i] == '.') {
				if(idxX != -1) {
					distToX[i].first = i - idxX - 1;
				}
			}else{
				idxX = i;
			}
		}

		idxX = -1;
		for(int i=n-1;i>=0;i--) {
			if(s[i] == '.') {
				if(idxX != -1) {
					distToX[i].second = idxX - i - 1;
				}
			}else{
				idxX = i;
			}
		}

		int maks = 0;
		for(int i=0;i<n;i++){
			if(distToX[i] != ii(inf,inf)) {

				maks = max(maks, min(distToX[i].first, distToX[i].second));
			}
		}

		printf("%d\n", maks);
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