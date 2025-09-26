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

int denominations[] = {10000, 1000, 100, 10, 1};

void solve(){
	int numPlayer,numRound;
	while(scanf("%d %d",&numPlayer,&numRound) == 2) {
		int ans = 0;
		for(int i=0;i<numRound;i++){
			int b;
			int bet;
			scanf("%d %d",&b, &bet);
			
			int sum = bet;
			for(int j=1;j<numPlayer;j++){
				int el;
				scanf("%d",&el);
				sum += el;
			}

			
			if(sum > b) {
				//fail, try smaller
				for(int j=0;j<5;j++){
					if(denominations[j] >= bet) {
						continue;
					}
					int val = sum;
					val -= bet;
					val += denominations[j];

					if(val <= b) {
						ans += denominations[j];
						break;
					}
				}
			}else{
				for(int j=0;j<5;j++){
					if(denominations[j] <= bet) {
						break;
					}

					int val = sum;
					val -= bet;
					val += denominations[j];

					if(val <= b) {
						ans += (denominations[j] - bet);
						break;
					}
				}
			}
		}

		printf("%d\n", ans);
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