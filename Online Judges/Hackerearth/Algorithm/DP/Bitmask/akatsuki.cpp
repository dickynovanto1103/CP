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

const int maxn = 25;
ii a[maxn],b[maxn];
int dp[25][1<<20];
int n;

int solve(int idx, int bit){
	if(bit == ((1<<n) - 1)){return 0;}
	if(dp[idx][bit] != -1){return dp[idx][bit];}

	int i;
	int ans = inf;
	for(i=0;i<n;i++){
		if(!((1<<i) & bit)){
			int jarak = abs(a[idx].first - b[i].first) + abs(a[idx].second - b[i].second);
			ans = min(ans, solve(idx+1, bit | (1<<i)) + jarak);
		}
	}
	return dp[idx][bit] = ans;
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].first,&a[i].second);
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&b[i].first,&b[i].second);
	}

	memset(dp, -1, sizeof dp);
	int ans = solve(0,0);

	printf("%d\n",ans);

	return 0;
};