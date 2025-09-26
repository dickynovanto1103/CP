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
	int p, a, b, c, d, n;
	// cout<<"EOF: " << EOF<<endl;
	while(scanf("%d %d %d %d %d %d",&p,&a,&b,&c,&d,&n) != EOF) {
		double prices[n+10];
		for(int i=1;i<=n;i++){
			prices[i] = p * (sin(a * i + b) + cos(c * i + d) + 2);
			// printf("prices[%d]: %lf\n", i, prices[i]);
		}

		double minim = prices[n];
		double maxDecline = 0;
		for(int i=n-1;i>=1;i--){
			maxDecline = max(maxDecline, prices[i] - minim);
			minim = min(minim, prices[i]);
			// printf("minim: %lf, prices[%d]: %lf, decline now: %lf, maxDecline now: %lf\n", minim, i, prices[i], prices[i] - minim, maxDecline);
		}

		printf("%.10lf\n", maxDecline);
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