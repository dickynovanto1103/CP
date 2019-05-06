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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 100;

int a[maxn], b[maxn], c[maxn], s[maxn];

int cnt[81][1<<9];
int dp[81][1<<9];
int n;

int solveCnt(int idx, int mask) {
	if(idx == n){return 0;}
	if(cnt[idx][mask] != -1){return cnt[idx][mask];}
	bool valid = true;
	int i,j;
	if((1<<a[idx]) & mask){valid = false;}
	if((1<<b[idx]) & mask){valid = false;}
	if((1<<c[idx]) & mask){valid = false;}
	
	// printf("valid: %d\n",valid);
	if(valid) {
		int baru = mask;
		baru |= (1<<a[idx]); baru |= (1<<b[idx]); baru |= (1<<c[idx]);
		assert(baru != mask);
		return cnt[idx][mask] = max(solveCnt(idx+1, mask), 1 + solveCnt(idx+1, baru));
	}else{
		return cnt[idx][mask] = solveCnt(idx+1, mask);
	}
}

int solveDp(int idx, int mask)  {
	if(idx == n){
		if(mask != ((1<<9) - 1)){return -inf;}
		else{return 0;}
	}
	int i,j;
	if(dp[idx][mask] != -1){return dp[idx][mask];}
	bool valid = true;
	if((1<<a[idx]) & mask){valid = false;}
	if((1<<b[idx]) & mask){valid = false;}
	if((1<<c[idx]) & mask){valid = false;}

	if(valid) {
		int baru = mask;
		baru |= (1<<a[idx]); baru |= (1<<b[idx]); baru |= (1<<c[idx]);
		assert(baru != mask);
		return dp[idx][mask] = max(solveDp(idx+1, mask), s[idx] + solveDp(idx+1, baru));
	}else{
		return dp[idx][mask] = solveDp(idx+1, mask);
	}
}

int main(){
	int i,j;
	int tc = 1;
	while(scanf("%d",&n),n){
		memset(cnt, -1, sizeof cnt); memset(dp, -1, sizeof dp);
		printf("Case %d: ",tc++);
		for(i=0;i<n;i++){
			scanf("%d %d %d %d",&a[i], &b[i], &c[i], &s[i]);
			a[i]--; b[i]--; c[i]--;
		}
		
		int maksCnt = solveCnt(0, 0);
		// printf("maksCnt: %d\n",maksCnt);
		assert(maksCnt <= 3);
		if(maksCnt < 3){printf("-1\n"); continue;}
		int maksDP = solveDp(0,0);
		if(maksDP < 0){printf("-1\n");}
		else{printf("%d\n",maksDP);}
	}
	return 0;
};