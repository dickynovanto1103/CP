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
	int bytes;
	int tt = 0;
	vector<int> trans(5);

	while(scanf("%d",&bytes) && bytes > 0) {
		printf("Output for data set %d, %d bytes:\n", ++tt, bytes);
		int tempBytes = bytes;
		int sz = 0;
		int totSeconds = 0;
		
		while(tempBytes) {
			int num;
			scanf("%d",&num);
			totSeconds++;
			tempBytes -= num;
			trans[sz] = num;
			sz++;
			if(sz == 5) {
				int sum = 0;
				for(int i=sz-1;i>=sz-5;i--){
					sum += trans[i];
				}
				printf("   Time remaining: ");
				if(sum == 0) {
					puts("stalled");
				}else{
					int remainingSeconds = ceil(5.0 * tempBytes / sum);
					printf("%d seconds\n", remainingSeconds);
				}
				sz = 0;
			}
		}
		printf("Total time: %d seconds\n", totSeconds);


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