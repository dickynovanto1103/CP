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
	int n,m,a,b;
	while(scanf("%d%d%d%d",&n,&m,&a,&b) != EOF) {
		int minim = inf;
		for(int i=0;i<=n;i++){
			int rem = n - i;
			int costOfM = ((rem + m - 1) / m) * b;
			int cost = i * a + costOfM;
			minim = min(minim, cost);
		}

		printf("%d\n", minim);
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