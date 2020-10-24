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
typedef vector<ii> vii;

template<typename T>
T dinic_flow(vector<pair<int,T> >* adjlist, int* level, T** flow, T** capacity, int s, int t, T aug) {
	if (aug == 0 || s == t) return aug;
	T total_flow = 0;
	for (int i = 0; aug != 0 && i < (int) adjlist[s].size(); i++) {
		pair<int,T> edge = adjlist[s][i];
		if (level[s] + 1 == level[edge.first]) {
			T new_aug = capacity[s][edge.first] - flow[s][edge.first];
			T new_flow = dinic_flow(adjlist, level, flow, capacity, edge.first, t, aug < 0 ? new_aug : min(aug, new_aug));
			total_flow += new_flow;
			flow[s][edge.first] += new_flow;
			flow[edge.first][s] -= new_flow;
			aug -= new_flow;
		}
	}
	return total_flow;
}

template<typename T>
T dinic(int n, vector<pair<int,T> >* adjlist, int s, int t) {
	printf("n: %d\n",n);
	T maxflow = 0;

	T** flow = new T*[n];
	T** capacity = new T*[n];
	vector<int> *adj = new vector<int>[n];
	for (int i = 0; i < n; i++) {
		flow[i] = new T[n];
		capacity[i] = new T[n];
		for (int j = 0; j < n; j++)
			flow[i][j] = 0;
		for (int j = 0; j < (int) adjlist[i].size(); j++) {
			if (capacity[i][adjlist[i][j].first] == 0)
				adj[i].push_back(adjlist[i][j].first);
			capacity[i][adjlist[i][j].first] += adjlist[i][j].second;
		}
	}
	int* level = new int[n];

	while (1) {
		// printf("test\n");
		for (int i = 0; i < n; i++) level[i] = -1;
		level[s] = 0;
		queue<int> que; que.push(s);
		while (!que.empty()) {
			int t = que.front(); que.pop();
			for (int i = 0; i < (int) adj[t].size(); i++) {
				int next = adj[t][i];
				if (level[next] < 0 && flow[t][next] < capacity[t][next]) {
					level[next] = level[t] + 1;
					que.push(next);
				}
			}
		}
		// printf("t: %d level[%d]: %d\n", );
		if (level[t] < 0)
			break;
		T new_flow;
		while (new_flow = dinic_flow(adjlist, level, flow, capacity, s, t, (T) -1))
			maxflow += new_flow;
	}
	for (int i = 0; i < n; i++)
		delete [] flow[i], delete [] capacity[i];
	delete [] adj;
	delete [] flow;
	delete [] capacity;
	delete [] level;

	return maxflow;
}

vector<ii> adj[20011];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int u[10001], v[10001], w[10001];
	int maks = 0;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		maks = max(maks, w[i]);
	}
	int kiri = 1, kanan = maks, mid, ans = -1;
	// printf("test kiri: %d kanan: %d\n", kiri, kanan);
	while(kiri <= kanan){
		// printf("test\n");
		mid = (kiri + kanan)/2;
		for(i=0;i<=2*n;i++){
			adj[i].clear();
		}
		printf("mid: %d\n",mid);

		for(i=0;i<m;i++){
			if(w[i] <= mid){
				int next = v[i] + n;
				adj[u[i]].pb(ii(next, 1));
				adj[next].pb(ii(u[i], 1));
			}
		}
		int mcbm = dinic(2*n+5,adj, 0, 2*n+3);
		printf("mcbm: %d\n",mcbm);
		if(mcbm == n){
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	printf("%d\n",ans);
	
	return 0;
};