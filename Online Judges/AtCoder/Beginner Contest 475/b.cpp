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
	while(scanf("%d",&n) != EOF) {
		int a[n];
		int sum100 = 0, sum10 = 0, sum1 = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			int count1000 = ((a[i] + 999) / 1000);
			int change = 1000 * count1000 - a[i];
			// printf("firstChange: %d count1000: %d\n", change, count1000);

			int num100 = change / 100;
			change %= 100;
			int num10 = change / 10;
			change %= 10;
			int num1 = change;
			// printf("num100: %d num10: %d num1: %d\n", num100, num10, num1);
			sum100 += num100;
			sum10 += num10;
			sum1 += num1;
		}

		printf("%d %d %d\n", sum1, sum10, sum100);

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