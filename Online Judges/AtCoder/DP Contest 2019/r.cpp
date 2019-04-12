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

const int mod = 1e9 + 7;
const int maxn = 50;

void add(int &a, int b){
	a += b;
	if(a >= mod){a -= mod;}
}

int mul(int a, int b){
	return (ll)a * b % mod;
}

struct Mat{
	int a[maxn][maxn];
	int n;

	Mat(int n){
		int i,j;
		this->n = n;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				a[i][j] = 0;
			}
		}
	}
	
	Mat operator*(const Mat &b) const {
		int i,j,k;
		Mat c(n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					add(c.a[i][j], mul(a[i][k], b.a[k][j]));
				}
			}
		}
		return c;
	}
};

int main(){
	int n;
	ll k;
	scanf("%d %lld",&n,&k);
	int a[55][55];
	int i,j;
	Mat ans(n), ind(n), temp(n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			temp.a[i][j] = a[i][j];
		}
	}

	for(i=0;i<n;i++){
		ans.a[i][i] = 1;
	}

	while(k) {
		if(k%2){
			ans = ans * temp;
		}
		temp = temp*temp;
		k /= 2;
	}
	int jawab = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			add(jawab, ans.a[i][j]);
			// printf("ans[%d][%d]: %d\n",i,j,ans.a[i][j]);
		}
	}
	printf("%d\n",jawab);
	// naive dp

	// int dp[55][55];

	// for(i=0;i<n;i++){
	// 	dp[i][0] = 1;
	// }

	// for(i=0;i<k;i++){
	// 	for(j=0;j<n;j++){
	// 		for(int m=0;m<n;m++){
	// 			if(a[j][m]){
	// 				add(dp[m][i+1], dp[j][i]);
	// 			}
	// 		}
	// 	}
	// }

	// int ans = 0;
	// for(i=0;i<n;i++){
	// 	add(ans, dp[i][k]);
	// }

	// printf("%d\n",ans);
	return 0;
};