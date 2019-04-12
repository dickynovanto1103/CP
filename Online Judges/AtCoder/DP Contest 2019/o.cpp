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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 21;

int dp[1<<maxn];
const int mod = 1e9 + 7;

void add(int &a, int b){
	a += b;
	if(a >= mod){a -= mod;}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn][maxn];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dp[0] = 1;
	
	for(int k=0;k<(1<<n);k++){
		i = __builtin_popcount(k);
		for(j=0;j<n;j++){
			if(a[i][j] == 0){continue;}
		
			if(!(k & (1<<j))){
				add(dp[k | (1<<j)], dp[k]);
			}
		}
	}

	printf("%d\n",dp[(1<<n)-1]);
	return 0;
};