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

vector<vi> AdjList;

const int maxn = 50010;
int dist[maxn];

void bfs(int node){
	// queue<int> q;

	// q.push(node);
	// dist[node] = 0;
	// while(!q.empty()){
	// 	int front = q.front(); q.pop();
	// 	for(int i=0;i<AdjList[front].size();i++){
	// 		int v = AdjList[front][i];
	// 		if(dist[v] == -1){
	// 			dist[v] = dist[node] + 1;
	// 			q.push(v);
	// 		}
	// 	}
	// }
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(dist[v] == -1){
			dist[v] = dist[node] + 1;
			bfs(v);
		}
	}
}
int cnt[maxn];

void coba(int node, int k, int parent){
	cnt[node]++;
	if(k == 0){return;}
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent){
			coba(v, k-1, node);
		}
		
	}	
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(cnt, 0, sizeof cnt);
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		AdjList.assign(n+1,vi());
		for(i=0;i<(n-1);i++){
			int a,b;
			scanf("%d %d",&a,&b);
			AdjList[a].pb(b); AdjList[b].pb(a);
		}
		
		memset(dist, -1, sizeof dist);
		int a[maxn];
		for(i=0;i<m;i++){
			scanf("%d",&a[i]);
		}
		dist[a[0]] = 0;
		bfs(a[0]);
		int maks = -1, maksIdx = 1;
		for(i=0;i<m;i++){
			if(dist[a[i]] == inf){continue;}
			if(maks < dist[a[i]]){
				maks = dist[a[i]];
				maksIdx = a[i];
			}
		}
		int walikota1 = maksIdx, walikota2 = 1;

		memset(dist, -1, sizeof dist);
		dist[walikota1] = 0;
		bfs(walikota1);
		maks = -1, maksIdx = 1;
		for(i=0;i<m;i++){
			if(dist[a[i]] == inf){continue;}
			if(maks < dist[a[i]]){
				maks = dist[a[i]];
				maksIdx = a[i];
			}
		}
		walikota2 = maksIdx;
		// printf("walikota1: %d walikota2: %d\n",walikota1, walikota2);
		coba(walikota1, k, -1);
		coba(walikota2, k, -1);
		// for(i=1;i<=n;i++){
		// 	printf("cnt[%d]: %d\n",i,cnt[i]);
		// }
		int ans = 0;
		for(i=1;i<=n;i++){
			if(cnt[i] == 2){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};