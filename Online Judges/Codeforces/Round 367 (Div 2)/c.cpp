#include <bits/stdc++.h>

using namespace std;
#define inf 1e18
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

void minim(ll &a, ll b){
	a = min(a,b);
}

string s[maxn][2];
ll dp[maxn][2];

int main(){
	int n,c[maxn], i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	
	for(i=0;i<n;i++){
		cin>>s[i][0];
		s[i][1] = s[i][0];
		reverse(s[i][1].begin(), s[i][1].end());
		dp[i][0] = dp[i][1] = inf;
	}

	dp[0][0] = 0; dp[0][1] = c[0];
	for(i=1;i<n;i++){
		bool valid = false;
		for(j=0;j<2;j++){
			for(int k=0;k<2;k++){
				if(s[i][j] >= s[i-1][k] && dp[i-1][k] != inf){
					valid = true;
					minim(dp[i][j], dp[i-1][k] + (j == 1 ? c[i] : 0));
					// printf("j: %d k: %d\n",j,k);
					// printf("dp[%d][%d]: %lld\n",i,j,dp[i][j]);
				}
			}
		}
		if(!valid){printf("-1\n"); return 0;}
	}
	ll ans = min(dp[n-1][0], dp[n-1][1]);
	printf("%lld\n",ans);
	return 0;
};