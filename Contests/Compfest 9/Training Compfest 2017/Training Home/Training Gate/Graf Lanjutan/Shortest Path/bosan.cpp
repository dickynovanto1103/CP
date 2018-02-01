#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define mod 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dist;
ll memo[100001];
int n;

ll solve(int awal){
	if(awal==n){return 1;}
	if(memo[awal]!=-1){return memo[awal];}
	ll ans = 0;
	for(int i=0;i<AdjList[awal].size();i++){
		ii v = AdjList[awal][i];
		if(dist[v.first] == dist[awal] + v.second){
			ans+=solve(v.first);
			ans%=mod;
		}
	}
	return memo[awal] = ans;
}

int main() {
	int m,u,v,w,i;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vii());
	for(i=0;i<m;i++){scanf("%d %d %d",&u,&v,&w); AdjList[u].pb(ii(v,w)); AdjList[v].pb(ii(u,w));}
	priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0,1));
	
	dist.assign(n+1,inf);
	dist[1] = 0;
	while(!pq.empty()){

		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u]){continue;}
		for(i=0;i<AdjList[u].size();i++){
			ii v = AdjList[u][i];
			if(dist[v.first] > dist[u] + v.second){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	memset(memo,-1,sizeof memo);
	ll ans = (solve(1))%mod;
	printf("%lld\n",ans);
	return 0;
}