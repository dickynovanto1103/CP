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

const int maxn = 1e2 + 3;
ll memo[2*maxn][2*maxn];
ll a[2*maxn][2*maxn];
int n;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		scanf("%d",&n);
		printf("Case %d: ",test++);
		// printf("\n\n");
		for(i=0;i<n;i++){
			for(j=0;j<=i;j++){
				memo[i][j] = -1;
				scanf("%lld",&a[i][j]);
				//printf("yang diinput: %lld\n",a[i][j]);
			}
		}
		int kolom = n-1;
		for(i=n;i<2*n-1;i++){
			//printf("kolom: %d\n",kolom);
			for(j=0;j<kolom;j++){
				memo[i][j] = -1;
				scanf("%lld",&a[i][j]);
				//printf("yang diinput: %lld\n",a[i][j]);
			}
			kolom--;
		}
		//dp
		memo[0][0] = a[0][0];
		for(i=1;i<n;i++){
			for(j=0;j<=i;j++){
				if(j==0){memo[i][j]=a[i][j] + memo[i-1][j];}
				else if(j==i){memo[i][j] = a[i][j] + memo[i-1][j-1];}
				else{memo[i][j] = a[i][j] + max(memo[i-1][j],memo[i-1][j-1]);}
			}
		}
		kolom = n-1;
		for(i=n;i<2*n-1;i++){
			for(j=0;j<kolom;j++){
				memo[i][j] = a[i][j] + max(memo[i-1][j],memo[i-1][j+1]);
			}
			kolom--;
		}

		printf("%lld\n",memo[2*n-2][0]);
	}
	return 0;
};