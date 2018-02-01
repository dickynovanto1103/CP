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

int s,n;
const int maxn = 2001;
ll memo[maxn][maxn];
ll v[maxn], w[maxn];

ll solve(int id, int sisaBerat){
	if(id==n){return 0;}
	if(w[id]>sisaBerat){return solve(id+1,sisaBerat);}
	if(memo[id][sisaBerat]!=-1){return memo[id][sisaBerat];}
	return memo[id][sisaBerat] = max(solve(id+1,sisaBerat), v[id] + solve(id+1, sisaBerat-w[id]));
}

int main(){
	scanf("%d %d",&s,&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%lld %lld",&w[i],&v[i]);
	}
	memset(memo,-1,sizeof memo);
	ll ans = solve(0,s);
	printf("%lld\n",ans);
	return 0;
};