/*
ID: dickyno1
LANG: C++14
TASK: nocows
*/

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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dp[201][100][2];

const int mod = 9901;

int getMinHeight(int remNode) {
	int height = 0;
	for(int i=1;i<10;i++){
		int upper = 1<<i;
		if(remNode < upper) {
			height = i;
			break;
		}
	}

	return height;
}

int getMaxHeight(int remNode) {
	return remNode / 2  + 1;
}

bool canReachLeaf(int heightLeft, int remNode) {
	int minHeight = getMinHeight(remNode);
	int maxHeight = getMaxHeight(remNode);
	// printf("heightLeft: %d remNode: %d minHeight: %d maxHeight: %d\n", heightLeft, remNode, minHeight, maxHeight);
	return minHeight <= heightLeft && heightLeft <= maxHeight;
}

int solve(int remNode, int heightLeft, int mustReachLeaf) {
	// printf("remNode: %d heightLeft: %d mustReachLeaf: %d\n", remNode, heightLeft, mustReachLeaf);
	if(mustReachLeaf && !canReachLeaf(heightLeft + 1, remNode)){
		return 0;
	}
	if(remNode % 2 == 0) return 0;
	if(heightLeft == 0) {
		if(remNode != 1){return 0;}
		return 1;
	}
	if(remNode == 1) {
		if(mustReachLeaf) {
			if(heightLeft == 0) return 1;
			return 0;
		}
		return 1;
	}
	
	if(dp[remNode][heightLeft][mustReachLeaf] != -1){return dp[remNode][heightLeft][mustReachLeaf];}

	int ans = 0;
	for(int i=1;i<remNode;i+=2){
		int cntNode1 = i, cntNode2 = remNode - 1 - i;

		if(!mustReachLeaf) {
			int ans1 = solve(cntNode1, heightLeft - 1, false);
			int ans2 = solve(cntNode2, heightLeft - 1, false);
			// printf("cnt nodes: %d %d, false false, ans1: %d ans2: %d\n",cntNode1, cntNode2, ans1, ans2);
			ans += ans1 * ans2;
			ans %= mod;
			continue;
		}
		

		int ans1 = solve(cntNode1, heightLeft - 1, true);
		int ans2 = solve(cntNode2, heightLeft - 1, true);
		ans -= ans1 * ans2;
		// printf("cnt nodes: %d %d, true true, ans1: %d ans2: %d\n",cntNode1, cntNode2, ans1, ans2);
		ans %= mod;
		if(ans < 0){
			ans += mod;
		}
		
		ans1 = solve(cntNode1, heightLeft - 1, true);
		ans2 = solve(cntNode2, heightLeft - 1, false);
		// printf("cnt nodes: %d %d, true false, ans1: %d ans2: %d\n",cntNode1, cntNode2, ans1, ans2);
		ans += ans1 * ans2;
		ans %= mod;

		ans1 = solve(cntNode1, heightLeft - 1, false);
		ans2 = solve(cntNode2, heightLeft - 1, true);
		// printf("cnt nodes: %d %d, false true, ans1: %d ans2: %d\n",cntNode1, cntNode2, ans1, ans2);
		ans += ans1 * ans2;
		ans %= mod;
		
		
	}

	// printf("ans = dp[%d][%d]: %d\n", remNode, heightLeft, ans);
	return dp[remNode][heightLeft][mustReachLeaf] = ans;
}

int main(){
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);

	int n,k,i,j;
	while(scanf("%d %d",&n,&k) != EOF) {
		memset(dp, -1, sizeof dp);
		if(!canReachLeaf(k, n)) {
			puts("0");
			continue;
		}
		int ans = solve(n, k-1, true);
		printf("%d\n", ans);
	
	}
	// printf("n: %d k: %d\n",n,k);
	//dp[remNode][height]...how many ways can we form a binary tree with remNode left and at the height
	
	return 0;
};