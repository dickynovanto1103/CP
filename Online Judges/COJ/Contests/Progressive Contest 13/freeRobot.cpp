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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n;
// int dx[] = {-1,-1,0,1,1,1,0,-1};
// int dy[] = {0,1,1,1,0,-1,-1,-1};

// ll solve(int row, int col, bool isVisited[15][15], int step) {
// 	if(step == n){return 1;}
// 	ll ans = 0;
// 	for(int i=0;i<8;i++){
// 		int xbaru = row + dx[i], ybaru = col + dy[i];
// 		if(xbaru >= 0 && xbaru<=n && ybaru >= 0 && ybaru <= n){
// 			if(!isVisited[xbaru][ybaru]){
// 				isVisited[xbaru][ybaru] = true;
// 				ans += solve(xbaru, ybaru, isVisited, step + 1);
// 				isVisited[xbaru][ybaru] = false;
// 			}	
// 		}
		
// 	}
// 	return ans;
// }

int main(){
	bool isVisited[15][15];
	
	int tc;
	scanf("%d",&tc);

	ll ans[] = {1, 3, 15, 75, 391, 2065, 11091, 60215, 330003, 1820869, 10103153, 56313047, 315071801, 1768489771, 9953853677};
	while(tc--) {
		// memset(isVisited, false, sizeof isVisited);
		scanf("%d",&n);
		// isVisited[0][0] = true;

		printf("%lld\n",ans[n] );
	}
	return 0;
};