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
	int b, n;
	while(scanf("%d %d",&b,&n) && !(b == 0 || n == 0)) {
		int reserves[b+2];
		for(int i=1;i<=b;i++){
			scanf("%d",&reserves[i]);
		}
		for(int i=0;i<n;i++){
			int d, c, money;
			scanf("%d %d %d",&d,&c,&money);
			reserves[d] -= money;
			reserves[c] += money;
		}

		char c = 'S';
		for(int i=1;i<=b;i++){
			if(reserves[i] < 0) {
				c = 'N';
				break;
			}
		}
		printf("%c\n", c);
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