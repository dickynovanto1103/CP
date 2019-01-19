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

const int maxn = 1e2 + 2;

vector<vi> AdjList;

int dist[maxn];

void bfs(int titikAwal) {
	memset(dist, -1, sizeof dist);
	dist[titikAwal] = 0;
	queue<int> q;
	q.push(titikAwal);
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(int i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(dist[v] == -1) {
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}
}

int getDiameter() {
	int i;
	bfs(1);
	int maksDist = -1, titik;
	for(i=1;i<maxn;i++){
		if(maksDist < dist[i]){
			maksDist = dist[i];
			titik = i;
		}
	}
	bfs(titik);
	maksDist = -1;
	for(i=1;i<maxn;i++){
		if(maksDist < dist[i]){
			maksDist = dist[i];
			titik = i;
		}
	}
	return maksDist;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n,i,j;
	scanf("%d",&n);
	int ans = 0;
	for(i=0;i<n;i++){
		int banyak;
		scanf("%d",&banyak);
		AdjList.assign(banyak+1, vi());
		for(j=0;j<banyak-1;j++){
			int a,b;
			scanf("%d %d",&a,&b);
			AdjList[a].pb(b); AdjList[b].pb(a);

		}
		int d = getDiameter();
		ans += d;
	}
	printf("%d\n",ans);
	return 0;
};