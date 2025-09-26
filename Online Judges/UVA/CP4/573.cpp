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
	int h,f;
	double u,d;
	while(scanf("%d %lf %lf %d",&h,&u,&d,&f) && (h)) {
		double dropsBy = (f / 100.0) * u;
		double height = 0;
		bool success = false;
		int ans = 0;
		for(int i=1;;i++){
			height += u;
			if(height > h) {
				success = true;
				ans = i;
				break;
			}
			height -= d;
			if(height < 0) {
				ans = i;
				break;
			}
			u = max(0.0, u - dropsBy);

		}

		if(success) {
			printf("success on day %d\n", ans);
		}else{
			printf("failure on day %d\n", ans);
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