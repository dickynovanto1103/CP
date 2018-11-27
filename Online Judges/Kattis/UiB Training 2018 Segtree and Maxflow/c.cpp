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

const int maxn = 50010;

vector<vii> AdjList;

int main(){
	int k,n,m,o,i,j;
	scanf("%d %d %d %d",&k,&n,&m,&o);
	AdjList.assign(n, vii());
	ll dist[maxn];
	dist[0] = 0;
	for(i=1;i<maxn;i++){
		dist[i] = (ll)inf;
	}
	for(i=0;i<m;i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		AdjList[a].pb(ii(b,w));
		if(k == 1){
			dist[b] = (ll)w;
		}
	}

	if(k == 1){
		for(i=1;i<n;i++){
			dist[i] += dist[i-1];
			// printf("dist[%d]: %lld\n",i,dist[i]);
		}
		for(int tt=0;tt<o;tt++){
			int a,b;
			scanf("%d %d",&a,&b);
			ll jarak = dist[b] - (a == 0? 0: dist[a]);
			if(jarak >= inf){
				printf("-1\n");
			}else{
				printf("%lld\n",jarak);
			}
		}	
		return 0;	
	}

	

	for(int tt=0;tt<o;tt++){
		int a,b;
		scanf("%d %d",&a,&b);
		memset(dist, -1, sizeof dist);
		priority_queue<ii, vii, greater<ii> > pq;
		dist[a] = 0;
		pq.push(ii(dist[a], a));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int jarak = front.first, node = front.second;
			if(node > b){break;}
			if(jarak > dist[node]){continue;}
			for(i=0;i<AdjList[node].size();i++){
				ii v = AdjList[node][i];
				if(dist[v.first] == -1 || dist[v.first] > (dist[node] + v.second)){
					dist[v.first] = dist[node] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		printf("%lld\n",dist[b]);
	}
	return 0;
};