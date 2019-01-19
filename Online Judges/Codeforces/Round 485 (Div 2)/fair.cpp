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

const int maxn = 1e5 + 5;

vector<vi> AdjList, listBarang, listJarak;
int n;

void bfs(int idx) {

	queue<int> q;
	int dist[maxn],i,j;
	memset(dist, -1, sizeof dist);

	for(i=0;i<listBarang[idx].size();i++){
		int kota = listBarang[idx][i];
		dist[kota] = 0;
		q.push(kota);
	}

	while(!q.empty()){
		int front = q.front(); q.pop();
		
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(dist[v] == -1){
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}

	for(i=1;i<=n;i++){
		listJarak[i].pb(dist[i]);
	}
}

int main(){
	int i,j,m,k,s;
	scanf("%d %d %d %d",&n,&m,&k,&s);
	int a[maxn];
	AdjList.assign(maxn, vi()); listBarang.assign(101, vi()); listJarak.assign(maxn, vi());
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		listBarang[a[i]].pb(i+1);
	}
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}

	for(i=1;i<=k;i++){
		bfs(i);
	}

	for(i=1;i<=n;i++){
		sort(listJarak[i].begin(), listJarak[i].end());
		ll ans = 0;
		for(j=0;j<s;j++){
			ans += listJarak[i][j];
		}
		printf("%lld ",ans);
	}
	printf("\n");
	return 0;
};