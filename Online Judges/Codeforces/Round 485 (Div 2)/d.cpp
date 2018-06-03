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
vector<vi> AdjList, KotaBarang;

int dist[maxn][101];

int main(){
	int n,m,k,s,i,j;
	int a[maxn];
	
	scanf("%d %d %d %d",&n,&m,&k,&s);
	AdjList.assign(n+1,vi()); KotaBarang.assign(k+1,vi());
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		KotaBarang[a[i]].pb(i+1);
		
	}

	for(i=1;i<=n;i++) {
		for(j=1;j<=k;j++){
			dist[i][j] = inf;
		}
	}
	for(i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		AdjList[u].pb(v); AdjList[v].pb(u);
	}

	for(i=1;i<=k;i++) {
		queue<int> q;
		for(j=0;j<KotaBarang[i].size();j++){
			int kota = KotaBarang[i][j];
			dist[kota][i] = 0;
			q.push(kota);
		}
		while(!q.empty()) {
			int front = q.front(); q.pop();
			for(j=0;j<AdjList[front].size();j++){
				int v = AdjList[front][j];
				if(dist[v][i] == inf) {
					dist[v][i] = dist[front][i] + 1;
					q.push(v);
				}
			}
		}
	}

	for(i=1;i<=n;i++){
		if(i>1){printf(" ");}

		sort(dist[i]+1, dist[i] + k+1);
		// for(j=1;j<=k;j++){
		// 	printf("dist[%d][%d]: %d\n",i,j,dist[i][j]);
		// }
		ll sum = 0;
		for(j=1;j<=s;j++){
			sum+=dist[i][j];
		}
		printf("%lld",sum);
	}
	printf("\n");


	return 0;
};