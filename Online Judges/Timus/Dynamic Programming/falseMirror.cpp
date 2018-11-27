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

int n;
const int maxn = 20;
int dp[1<<maxn];
int a[maxn];

int solve(int bitmask){
	if(bitmask == ((1<<n) - 1)){
		return 0;
	}
	int& ans = dp[bitmask];
	if(ans != -1){return ans;}
	ans = inf;
	for(int i=0;i<n;i++){
		if(!((1<<i) & bitmask)){
			int mask = bitmask;
			int next1 = (i+1)%n;
			int next2 = (i+2)%n;
			mask |= (1<<i);
			mask |= (1<<next1);
			mask |= (1<<next2);
			int penambahan = 0;
			for(int j = 0;j<n;j++){
				if(!((1<<j) & mask)){
					penambahan += a[j];
				}
			}
			ans = min(ans, penambahan + solve(mask));
		}
	}
	return ans;
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	memset(dp,-1,sizeof dp);
	printf("%d\n",solve(0));
	return 0;
};