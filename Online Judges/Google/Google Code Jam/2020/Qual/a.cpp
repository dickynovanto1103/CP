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
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d",&n);
		int a[101][101];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int trace = 0;
		for(i=0;i<n;i++){
			trace += a[i][i];
		}
		int row = 0;
		for(i=0;i<n;i++){
			bool vis[101];
			memset(vis, false, sizeof vis);
			for(j=0;j<n;j++){
				int bil = a[i][j];
				if(vis[bil]){
					row++;
					break;
				}
				vis[bil] = true;
			}
		}
		int col = 0;
		for(j=0;j<n;j++){
			bool vis[101];
			memset(vis, false, sizeof vis);
			for(i=0;i<n;i++){
				int bil = a[i][j];
				// printf("a[%d][%d]: %d\n",j,i,bil);
				if (vis[bil]) {
					col++;
					break;
				}
				vis[bil] = true;
			}
		}
		printf("Case #%d: %d %d %d\n",tt, trace, row, col);
	}
	return 0;
};