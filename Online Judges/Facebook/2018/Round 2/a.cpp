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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

vector<vii> adj;

int dist[52];

int wrong(int awal, int akhir) {
	int cur = awal;
	int d = 0;
	int i,j;
	while(cur != akhir) {
		int tujuan = -1;
		int minJarak = inf;
		for(i=0;i<adj[cur].size();i++) {
			ii v = adj[cur][i];
			int tetangga = v.first, w = v.second;
			// printf("cur; %d tetangga: %d w: %d\n",cur, tetangga, w);
			if(minJarak > w) {
				minJarak = w;
				tujuan = tetangga;
			}else if(minJarak == w){
				assert(false);
			}
		}
		assert(tujuan != -1);
		cur = tujuan;
		d += minJarak;
	}
	return d;
}

int right(int awal, int akhir) {
	int i,j;
	for(i=awal;i<=akhir;i++){
		dist[i] = inf;
	}
	dist[awal] = 0;
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(dist[awal], awal));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int jarak = front.first, node = front.second;
		for(i=0;i<adj[node].size();i++){
			ii v = adj[node][i];
			int tetangga = v.first, w = v.second;
			if((dist[node] + w) < dist[tetangga]) {
				dist[tetangga] = dist[node] + w;
				pq.push(ii(dist[tetangga], tetangga));
			}
		}
	}
	assert(dist[akhir] != inf);
	return dist[akhir];
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		adj.clear();
		viii edgeList;
		printf("Case #%d: ",tt);
		int n,k;
		scanf("%d %d",&n,&k);
		// printf("n: %d k: %d\n",n, k);
		adj.assign(n+1, vii());
		if(n==2){
			printf("0\n");
			printf("1\n1 2 1\n");
			continue;
		}else{
			if(n <= k){
				int w = k-1;
				for(i=1;i<n;i++){
					adj[i].pb(ii(i+1,w));
					edgeList.pb(iii(ii(i, i+1), w));
					// printf("edge: %d %d w: %d\n",i, i+1, w);
					w--;
				}
				// printf("edge: %d %d w: %d\n",1, n, k);
				adj[1].pb(ii(n,k));
				edgeList.pb(iii(ii(1, n), k));
			}else{
				if(k <= 2){
					printf("0\n");
					printf("1\n1 %d 1\n",n);
					continue;
				}
				int minim = min(n, k);
				int w = k-1;
				for(i=1;i<minim-1;i++) {
					adj[i].pb(ii(i+1,w));
					edgeList.pb(iii(ii(i, i+1), w));
					w--;
				}
				assert(w > 0);
				adj[minim-1].pb(ii(n, w));
				adj[1].pb(ii(n, k));
				edgeList.pb(iii(ii(minim-1, n), w));
				edgeList.pb(iii(ii(1, n), k));
			}

			int rightAns = right(1,n);
			int wrongAns = wrong(1,n);
			printf("%d\n",abs(wrongAns - rightAns));
			printf("%d\n",(int)edgeList.size());
			for(i=0;i<edgeList.size();i++){
				iii edge = edgeList[i];
				printf("%d %d %d\n",edge.first.first, edge.first.second, edge.second);
			}
		}
	}
	
	return 0;
};