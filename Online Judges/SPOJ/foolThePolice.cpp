#include <bits/stdc++.h>

using namespace std;
#define inf 10000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 101;
const int maxt = 251;
ii memo[101][251];
int n;
ll time1[maxn][maxn];
ll risk[maxn][maxn];

ii solve(ll idx, ll t){
	if(t<0){return ii(inf,inf);}
	if(idx==n-1){return ii(0,0);}
	if(memo[idx][t]!=ii(-1,-1)){return memo[idx][t];}
	ii ans = ii(inf,inf);
	for(int i=0;i<n;i++){
		if(i==idx){continue;}
		ii jawab = solve(i, t-time1[idx][i]);
		if(jawab.first + risk[idx][i] < ans.first){
			ans.first = jawab.first + risk[idx][i];
			ans.second = jawab.second + time1[idx][i];
		}else if(jawab.first + risk[idx][i] == ans.first){
			ans.second = min(ans.second,jawab.second + time1[idx][i]);
		}
	}
	return memo[idx][t] = ans;
}

int main(){
	int tc,i,j,t;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&t);
		for(i=0;i<maxn;i++){//memset
			for(j=0;j<maxt;j++){
				memo[i][j] = ii(-1,-1);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%lld",&time1[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%lld",&risk[i][j]);
			}
		}
		ii ans = solve(0,t);
		if(ans==ii(inf,inf)){
			printf("-1\n");
		}else{
			printf("%lld %lld\n",ans.first,ans.second);
		}
	}
	return 0;
};