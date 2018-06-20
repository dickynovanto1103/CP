#include <bits/stdc++.h>

using namespace std;
#define inf 10000000000000000LL
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

const int maxn = 1e5 + 5;
vector<vii> AdjList;

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	AdjList.assign(n+1,vii());
	for(i=0;i<m;i++){
		int u,v;
		ll w;
		scanf("%d %d %lld",&u,&v,&w);
		AdjList[u].pb(ii(v,w)); AdjList[v].pb(ii(u,w));
	}
	priority_queue<ii,vii, greater<ii> > pq;
	ll dist[maxn];
	fill(dist, dist+maxn, inf);
	for(i=0;i<k;i++){
		int kota;
		scanf("%d",&kota);
		dist[kota] = 0;
		pq.push(ii(dist[kota], kota));
	}

	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		ll jarak = front.first;
		ll node = front.second;
		if(dist[node] < jarak){continue;}

		for(i=0;i<AdjList[node].size();i++){
			ii v = AdjList[node][i];
			ll berat = v.second;
			ll tetangga = v.first;

			if((dist[node] + berat) < dist[tetangga]) {
				dist[tetangga] = dist[node] + berat;
				pq.push(ii(dist[tetangga], tetangga));
			}
		}
	}
	ll minim = inf;
	for(i=1;i<=n;i++){
		if(dist[i]==0){continue;}
		minim = min(minim, dist[i]);
	}

	if(minim==inf){
		printf("-1\n");
	}else{
		printf("%lld\n",minim);
	}


	return 0;
};