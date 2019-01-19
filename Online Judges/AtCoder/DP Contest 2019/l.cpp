#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000000LL
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

const int maxn = 3e3 + 3;

ll dp[maxn][maxn][2];
ll a[maxn];

const ll invalid = -inf;

ll solve(int awal, int akhir, int id) {
	if(awal > akhir){return 0;}
	if(dp[awal][akhir][id] != invalid){return dp[awal][akhir][id];}
	if(id == 0){
		return dp[awal][akhir][id] = max(a[awal] + solve(awal+1, akhir, 1-id), a[akhir] + solve(awal, akhir-1, 1 - id));
	}else{
		return dp[awal][akhir][id] = min(-a[awal] + solve(awal+1, akhir, 1-id), -a[akhir] + solve(awal, akhir-1, 1 - id));
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			for(int k=0;k<2;k++){
				dp[i][j][k] = invalid;
			}
		}
	}

	printf("%lld\n",solve(0, n-1, 0));

	return 0;
};