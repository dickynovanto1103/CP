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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i;
	int x[3], y[3];
	scanf("%d",&tc);
	while(tc--){
		for(int i=0;i<3;i++){
			scanf("%d %d",&x[i], &y[i]);
		}
		int ans = abs(x[0] - x[1]) + abs(y[0] - y[1]);
		if(x[0] == x[1] && x[1] == x[2]) {
			int minim = min(y[1], y[0]);
			int maks = max(y[1], y[0]);
			if(minim < y[2] && y[2] < maks) {
				ans+=2;
			}
		} else if (y[0] == y[1] && y[1] == y[2]) {
			int minim = min(x[1], x[0]);
			int maks = max(x[1], x[0]);
			if(minim < x[2] && x[2] < maks) {
				ans+=2;
			}
		}
		// if(x[0] == x[1] || y[0] == y[1]) {
		// 	int ans;
		// 	if(x[0] == x[1]) {
		// 		ans = abs(y[0] - y[1]);
		// 		int minim = min(y[0], y[1]);
		// 		int maks = max(y[0], y[1]);
		// 		if(minim < y[2] && y[2] < maks && x[0] == x[2]) {
		// 			ans += 2;
		// 		}
		// 	}else {
		// 		ans = abs(x[0] - x[1]);
		// 		int minim = min(x[0], x[1]);
		// 		int maks = max(x[0], x[1]);
		// 		if(minim < x[2] && x[2] < maks && y[0] == y[2]) {
		// 			ans += 2;
		// 		}
		// 	}
		// 	printf("%d\n", ans);
		// }else{
		// 	printf("%d\n", abs(x[0] - x[1]) + abs(y[0] - y[1]));
		// }	
		printf("%d\n", ans);
	}
	
	
	return 0;
};