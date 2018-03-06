#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,ll> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;
ll a[maxn];
ll dist[maxn];

vector<vii> AdjList;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vii());
	for(i=0;i<m;i++){
		int bil1,bil2;
		ll w;
		scanf("%d %d %lld",&bil1,&bil2,&w);
		AdjList[bil1].pb(ii(bil2,w));
		AdjList[bil2].pb(ii(bil1,w));
	}
	priority_queue<ii,vii,greater<ii> > pq;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		dist[i] = a[i];
		pq.push(ii(dist[i],i));
	}
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		ll jarak = front.first, node = front.second;
		if(jarak > dist[node]){continue;}
		for(i=0;i<AdjList[node].size();i++){
			ii v = AdjList[node][i];
			ll berat = v.second, tetangga = v.first;
			if(berat*2LL + dist[node] < dist[tetangga]){
				dist[tetangga] = dist[node] + berat*2LL;
				pq.push(ii(dist[tetangga],tetangga));
			}
		}

	}
	// printf("test\n");
	for(i=1;i<=n;i++){
		if(i>1){printf(" ");}
		printf("%lld",dist[i]);
	}
	printf("\n");
	return 0;
};