#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[401][401][401];

int main() {
	int i,j,k,tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					a[i][j][k] = inf;
				}
			}
		}
		int m;
		scanf("%d",&m);
		for(i=0;i<m;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			a[x][y][z] = -inf;
		}
	}
	return 0;
}