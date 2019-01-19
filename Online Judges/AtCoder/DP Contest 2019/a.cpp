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

const int maxn = 1e5 + 5;

int dp[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	int h[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
	}
	dp[1] = abs(h[1] - h[0]);
	for(i=2;i<n;i++){
		dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]));
	}
	printf("%d\n",dp[n-1]);
	return 0;
};