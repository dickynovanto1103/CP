#include <bits/stdc++.h>

using namespace std;
#define inf 1e16
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

int n;
int t[2020], c[2020];

ll dp[2020][4040];

ll solve(int idx, int sisa) {
	if(idx == n){ //sisa != 0
		if(sisa < n) {
			return inf;	
		}else{
			return 0;
		}
	}
	if(dp[idx][sisa] != -1){return dp[idx][sisa];}
	return dp[idx][sisa] = min(solve(idx+1, sisa-1), c[idx] + solve(idx+1, min(sisa + t[idx], 4001)));
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&t[i],&c[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%lld\n",solve(0, n));
	return 0;
};