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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 51;
int a[maxn][maxn];

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int maks = 0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					maks = max(maks,a[i][j]*a[j][k]*a[k][i]);
				}
			}
		}
		printf("%d\n",maks);
	}
	return 0;
};