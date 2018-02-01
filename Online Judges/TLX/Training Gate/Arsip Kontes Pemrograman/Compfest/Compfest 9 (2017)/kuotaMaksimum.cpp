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

const int maxn = 101;
int w[maxn], v[maxn];
int n,m;
ll memo[maxn][100001];

ll solve(int id, int remaining){
	if(id==n){return 0;}
	if(remaining<w[id]){return memo[id][remaining]=solve(id+1,remaining);}
	if(memo[id][remaining]!=-1){return memo[id][remaining];}
	return memo[id][remaining] = max((ll)v[id] + solve(id,remaining-w[id]), solve(id+1,remaining));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				memo[i][j] = -1;
			}
		}
		for(i=0;i<n;i++){scanf("%d",&w[i]);}
		for(i=0;i<n;i++){scanf("%d",&v[i]);}
		ll ans = solve(0,m);
		printf("%lld\n",ans);
	}	
	return 0;
};