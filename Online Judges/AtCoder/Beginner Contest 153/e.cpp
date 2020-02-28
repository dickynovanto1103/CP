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

int a[1010], b[1010],n;
int dp[10001][1001];

int solve(int h, int idx){
	if(idx == n){
		if(h <= 0){return 0;}
		else{return inf;}
	}
	if(h <= 0){return 0;}
	if(dp[h][idx] != -1){return dp[h][idx];}
	int cond1 = solve(h, idx+1);
	int cond2 = b[idx] + solve(h-a[idx], idx);
	int cond3 = b[idx] + solve(h-a[idx], idx+1);
	int ans = min(cond1, min(cond2, cond3));
	return dp[h][idx] = ans;
}

int main(){
	int h,i,j;
	scanf("%d %d",&h,&n);

	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%d\n",solve(h, 0));

	return 0;
};