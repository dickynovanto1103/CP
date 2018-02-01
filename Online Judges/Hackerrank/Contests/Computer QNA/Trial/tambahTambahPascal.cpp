#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 52;
ll memo[maxn][maxn];

int main() {
	int n,i,j;
	scanf("%d",&n);
	memo[0][0] = 1;
	for(i=1;i<n;i++){
		for(j=0;j<=i;j++){
			if(j==0 || j==i){memo[i][j] = 1; continue;}
			memo[i][j] = memo[i-1][j] + memo[i-1][j-1];
		}
	}
	for(i=0;i<n;i++){
		ll sum = 0;
		for(j=0;j<=i;j++){
			if(j){printf("+");}
			printf("%lld",memo[i][j]);
			sum+=memo[i][j];
		}
		printf("=%lld\n",sum);
	}
	return 0;
}