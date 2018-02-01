#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,j,k;
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n",tt);
		scanf("%d",&n);
		int x[105],y[105];
		for(i=0;i<n;i++){
			scanf("%d %d",&x[i],&y[i]);
		}
		double mat[105][105];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){mat[i][j] = 0;}
				else{mat[i][j] = inf;}
			}
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				double jarak = hypot(x[i]-x[j],y[i]-y[j]);
				if(jarak<10.0 || fabs(jarak-10.0)<eps){
					mat[i][j] = mat[j][i] = jarak;
				}
			}
		}
		for(k=0;k<n;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(mat[i][j] > mat[i][k] + mat[k][j]){
						mat[i][j] = mat[j][i] = mat[i][k] + mat[k][j];
					}
				}
			}
		}
		double ans = -inf;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				ans = max(ans,mat[i][j]);
			}
		}
		if(ans>=inf){printf("Send Kurdy\n\n");}
		else{printf("%.4lf\n\n",ans);}
	}
	return 0;
}