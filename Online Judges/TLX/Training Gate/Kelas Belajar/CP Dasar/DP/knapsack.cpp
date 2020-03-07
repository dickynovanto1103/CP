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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int w[101], v[101];
int n,batas;
int dp[101][2001];
int par[101][2001];
// bool truePar[101][2001];

int getKnapsackValue() {
	int i,j;
	memset(dp, -1, sizeof dp);
	memset(par, -1, sizeof par);
	for(i=0;i<n;i++){
		dp[i][0] = 0;
	}

	for(i=0;i<n;i++) {
		//consider beli
		for(j=0;j<=batas;j++){
			if(dp[i][j] == -1) {
				continue;
			}

			if((j + w[i]) > batas) {
				continue;
			}
			
			if(dp[i + 1][j + w[i]] < (dp[i][j] + v[i])) {
				dp[i + 1][j + w[i]] = dp[i][j] + v[i];
				par[i + 1][j + w[i]] = i;
			}
		}

		for(j=0;j<=batas;j++){
			if(dp[i + 1][j] < dp[i][j]) {
				dp[i + 1][j] = dp[i][j];
				par[i + 1][j] = par[i][j];
			}
		}
	}

	int maks = 0;

	for(i=0;i<=batas;i++) {
		maks = max(maks, dp[n][i]);
	}

	return maks;
}

int getMinWeight(int knapsackVal) {
	int minWeight = inf;
	for(int i=0;i<=batas;i++){
		if(dp[n][i] == knapsackVal) {
			return i;
		}
	}
	return minWeight;
}

int getIdx(int knapSackVal, int minWeight) {
	int i,j;
	for(i=0;i<=n;i++){
		if(dp[i][minWeight] == knapSackVal) {
			return i;
		}
	}
	return -1;
}

vector<int> getAllGoods(int idx, int minWeight) {
	vector<int> v;
	int nextIdx = idx, weight = minWeight;
	while(par[nextIdx][weight] != -1) {
		//we need to check true par or not
		v.pb(par[nextIdx][weight]);
		nextIdx = par[nextIdx][weight];
		weight -= w[nextIdx];
	}
	assert(weight == 0);
	reverse(v.begin(), v.end());
	return v;
}

int main(){
	int i,j;
	scanf("%d %d",&batas,&n);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&w[i],&v[i]);
	}
	//find knapsack value
	int val = getKnapsackValue();
	int minWeight = getMinWeight(val);
	assert(minWeight != inf);
	// printf("val: %d minWeight; %d\n",val, minWeight);
	int idx = getIdx(val, minWeight);
	// printf("idx: %d\n",idx);
	assert(idx != -1);
	vi ans = getAllGoods(idx, minWeight);

	for(i=0;i<ans.size();i++){printf("%d\n",ans[i]+1);}

	return 0;
};