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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;

int a[1010][1010];

int main(){
	int n,i,j;
	int tt = 1;

	while(scanf("%d",&n),n){
		printf("%d. ",tt++);
		int mat[1010][2];
		memset(mat, 0, sizeof mat);
		int sum = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				sum += a[i][j];
				mat[i][0] += a[i][j];
				mat[j][1] += a[i][j];
			}
		}
		// vi listBil;
		int tot = 0;
		int satunya = 0;
		for(i=0;i<n;i++){
			int ans = mat[i][1] - mat[i][0];
			// listBil.pb(mat[i][1] - mat[i][0]);
			if(ans < 0){
				tot += -ans;
			}else{
				satunya += ans;
			}
		}
		assert(satunya == tot);
		printf("%d %d\n",sum, tot);
	}
	

	return 0;
};