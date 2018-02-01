#include <bits/stdc++.h>

using namespace std;

#define inf 1000000000
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
ll dist[100010][35];
int main(){
	int n,m,a,b,tc,test=1,i,j;
	int awal[100010], akhir[100010], w[100010];
	
	scanf("%d",&tc);
	//printf("tc: %d\n",tc);
	while(tc--){
		//printf("tc: %d\n",tc);
		printf("Case #%d: ",test++);
		scanf("%d %d %d %d",&n,&m,&a,&b);
		AdjList.assign(n+1,vii());
		//printf("Test\n");
		//inisialisasi nilai dist
		for(i=1;i<=n;i++){
			for(j=0;j<=30;j++){
				dist[i][j] = inf;
			}
		}
		//printf("Test2\n");
		for(i=0;i<m;i++){
			scanf("%d %d %d",&awal[i], &akhir[i], &w[i]);
			int t1=awal[i],t2=akhir[i];
			AdjList[t1].push_back(ii(t2,w[i])); AdjList[t2].push_back(ii(t1,w[i])); 
		}
		//dijkstra dari start
		dist[a][0] = 0;
		priority_queue<iii> pq; pq.push(make_pair(0,ii(a,0))); // nilai_dist, node, n_edge
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			ll d = -front.first;
			int u = front.second.first, nedge_awal = front.second.second;
			if(d != dist[u][nedge_awal]) continue;
			for(i=0;i<AdjList[u].size();i++){
				ii v = AdjList[u][i];
				//printf("awal: %d\n",awal);
				int nedge = min(nedge_awal+1,30);
				if(d + v.second < dist[v.first][nedge]){
					dist[v.first][nedge] = d + v.second;

					pq.push(make_pair(-(dist[v.first][nedge]),ii(v.first,nedge)));
					//printf("yang dipush: %d\n",dist[v.first][nedge]);
				}
			}
		}
		ll ans = inf;
		for(i=0;i<=30;i++){
			if(1<<i <= dist[b][i]){ans=min(ans,dist[b][i]*2);}
			else{ans = min(ans,dist[b][i]);}
		}
		if(ans==inf){ans=-1;}
		printf("%d\n",ans);

		AdjList.clear();
	}
	return 0;
}