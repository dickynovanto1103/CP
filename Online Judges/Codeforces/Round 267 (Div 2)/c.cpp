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

const int maxn = 5001;

ll dp[maxn][maxn];
ll a[maxn];
int n,m,k;
ll solve(int idx, int banyakSegment, int banyakAmbil){
	if(idx == n){
		if(banyakSegment == k){return 0;}
		else{return -inf;}
	}
	if(banyakSegment == (k+1)){return 0;}
	if(banyakAmbil == m){}
}

int main(){
	memset(dp, -1, sizeof dp);
	int i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	solve()
	return 0;
};