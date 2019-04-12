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

const int maxn = 101;
int a[maxn];
int dist[maxn];
vector<vii> AdjList;

int dp[maxn];

int solve(int node) {
	if(node == 1){return 0;}
	if(dp[node] != -1){return dp[node];}
	int ans = 0;
	for(int i=0;i<AdjList[node].size();i++){
		ii v = AdjList[node][i];
		int tetangga = v.first, berat = v.second;
		if(dist[tetangga] == dist[node] - berat) {
			// printf("node: %d ke tetangga: %d\n",node, tetangga);
			ans = max(ans, a[tetangga] + solve(tetangga));
		}
	}
	return dp[node] = ans;
}

int main(){
	int n,i,j,m;
	scanf("%d",&n);
	AdjList.assign(maxn, vii());
	memset(dp, -1, sizeof dp);
	for(i=1;i<=n;i++){
		dist[i] = inf;
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		AdjList[a].pb(ii(b,w));
		AdjList[b].pb(ii(a,w));
	}
	priority_queue<ii, vii, greater<ii> > pq;

	dist[1] = 0;
	pq.push(ii(dist[1],1));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int jarak = front.first, node = front.second;
		if(jarak > dist[node]){continue;}
		for(i=0;i<AdjList[node].size();i++){
			ii v = AdjList[node][i];
			int tetangga = v.first, berat = v.second;
			if(dist[node] + berat < dist[tetangga]){
				dist[tetangga] = dist[node] + berat;
				pq.push(ii(dist[tetangga], tetangga));
			}
		}
	}

	// for(i=1;i<=n;i++){
	// 	printf("dist[%d]: %d\n",i,dist[i]);
	// }

	if(dist[n] == inf){printf("impossible\n");}
	else{
		printf("%d %d\n",dist[n],a[n] + solve(n));

	}
	return 0;
};