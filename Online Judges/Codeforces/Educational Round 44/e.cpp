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

const int maxn = 5e5 + 5;

int bit[maxn];
int dp[maxn];
ll n;

void update(int idx, int val) {
	// printf("proses update idx: %d\n",idx);
	for(int i=idx;i<=n;i += (i&-i)) {
		// printf("i: %d\n",i);
		bit[i] += val;
	}
}

int get(int idx) {
	int sum = 0;
	if(idx<0){return 0;}
	// printf("proses get idx: %d\n",idx);
	for(int i=idx;i>=1;i -= (i&-i)) {
		// printf("i: %d\n",i);
		sum+=(bit[i]);
	}
	return sum;
}

int main(){
	ll k,d;
	int a[maxn];
	scanf("%lld %lld %lld",&n,&k,&d);
	if(k==1){printf("YES\n"); return 0;}
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);


	if(a[k] - a[1] > d){
		printf("NO\n");
		return 0;
	}

	for(i=1;i<k;i++){
		dp[i] = 0;
	}
	dp[k] = 1;
	update(k,1);

	for(i=k+1;i<=n;i++){
		int batasIdxAtas = i-k;
		int minValue = a[i] - d;
		int idxMinValue = lower_bound(a+1,a+1+n,minValue) - a - 1;
		if(idxMinValue == 0) {
			dp[i] = 1;
			update(i,1);
			continue;
		}
		// printf("a[%d]: %d batasIdxAtas: %d idxMinValue: %d\n",i,a[i],batasIdxAtas, idxMinValue);

		if(idxMinValue>batasIdxAtas) {
			dp[i] = 0;
		}else{
			
			int banyak1 = get(batasIdxAtas) - get(idxMinValue-1);
			// printf("banyak1: %d\n", banyak1);
			if(banyak1>0) {
				dp[i] = 1;
				update(i,1);
			}else{
				dp[i] = 0;
			}
		}
	}
	// for(i=0;i<=n;i++){
	// 	printf("dp[%d]: %d\n",i,dp[i]);
	// }

	if(dp[n]==1){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;
};