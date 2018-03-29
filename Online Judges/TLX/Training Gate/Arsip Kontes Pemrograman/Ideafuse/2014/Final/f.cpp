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

const int maxn = 101;
ii segment[maxn];
int dp[maxn][maxn][maxn];
int n;
bool cmp(ii a, ii b){
	if(a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int solve(int idx, int start, int budget) {
	// printf("idx: %d start: %d budget: %d\n",idx,start,budget);
	if(idx==n){return start;} //kemaren return segment[idx-1].second
	int biaya = segment[idx].second - segment[idx].first;
	if(biaya > budget){return dp[idx][start][budget] = solve(idx+1, start, budget);}
	if(segment[idx].first > (start + 1)){return dp[idx][start][budget] = start;}
	if(dp[idx][start][budget] != -1){return dp[idx][start][budget];}
	return dp[idx][start][budget] = max(solve(idx+1, start, budget), solve(idx+1, segment[idx].second, budget-biaya));
}


int main(){
	int tc,p,budget,i,j,k;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++) {
		printf("Case #%d: ",tt);
		scanf("%d %d %d",&p,&budget, &n);
		
		for(i=0;i<=n;i++){//memset
			for(j=0;j<=100;j++){
				for(k=0;k<=budget;k++){
					dp[i][j][k] = -1;
				}
			}
		}
		for(i=0;i<n;i++) {
			scanf("%d %d",&segment[i].first,&segment[i].second);
		}

		sort(segment, segment+n, cmp);

		int ans = solve(0, 0, budget);
		printf("%d\n",ans);

	}
	return 0;
};