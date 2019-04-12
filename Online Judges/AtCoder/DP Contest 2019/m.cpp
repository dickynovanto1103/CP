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

const int maxn = 103;
const int mod = 1e9 + 7;

int dp[2][100001];

void add(int &a, int b){
	if(b < 0){b += mod;}
	a += b;
	if(a >= mod){a-=mod;}
}

int main(){
	int n,k,i,j;
	int a[maxn];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<=k;i++){
		if(a[0] >= i){dp[0][i] = 1;}
	}
	// printf("n: %d\n",n);
	int pref[100001];
	for(i=1;i<n;i++){
		int idx = i%2;

		if(idx == 1){
			memset(dp[1], 0, sizeof dp[1]);
			for(j=0;j<=k;j++){
				pref[j] = dp[0][j];
				if(j){add(pref[j], pref[j-1]);}
			}
		}else{
			memset(dp[0], 0, sizeof dp[0]);
			for(j=0;j<=k;j++){
				pref[j] = dp[1][j];
				if(j){add(pref[j], pref[j-1]);}
			}
		}

		for(j=0;j<=k;j++){
			int maks = j, minim = max(0, j-a[i]);
			int tambah = pref[maks] - (minim ? pref[minim-1]: 0);

			add(dp[idx][j], tambah);
			// printf("dp[%d][%d]: %d\n",i,j,dp[idx][j]);
		}
	}
	int idx = (n-1) % 2;
	printf("%d\n",dp[idx][k]);
	return 0;
};