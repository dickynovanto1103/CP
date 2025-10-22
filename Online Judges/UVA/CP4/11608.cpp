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
	int problemReady;
	int tc = 1;
	while(scanf("%d",&problemReady), problemReady >= 0) {
		printf("Case %d:\n", tc++);
		int problemCreated[12], problemsNeeded[12];
		for(int i=0;i<12;i++){
			scanf("%d",&problemCreated[i]);
		}
		for(int i=0;i<12;i++){
			scanf("%d",&problemsNeeded[i]);
		}

		for(int i=0;i<12;i++){
			if(problemReady >= problemsNeeded[i]) {
				problemReady -= problemsNeeded[i];
				puts("No problem! :D");
			}else{
				puts("No problem. :(");
			}

			problemReady += problemCreated[i];
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