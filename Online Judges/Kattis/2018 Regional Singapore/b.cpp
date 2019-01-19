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

const int maxn = 5e5 + 5;

vector<vi> AdjList;
bool isVisited[maxn];

void dfs(int n){
	int i,j;
	isVisited[n] = true;
	for(i=0;i<AdjList[n].size();i++){
		int v = AdjList[n][i];
		if(!isVisited[v]){
			dfs(v);
		}
	}
}

int warna[maxn];
bool vis[maxn];
bool isBipartite(int node){
	warna[node] = 0;
	vis[node] = true;
	bool apakahBipartite = true;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(int i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(warna[v] == warna[front]){return false;}
			else if(warna[v] == -1){
				warna[v] = 1 - warna[front];
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return true;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	memset(isVisited, false, sizeof isVisited);
	memset(vis, false, sizeof vis);
	memset(warna, -1, sizeof warna);
	AdjList.assign(maxn, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--; b--;
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}
	int cnt = 0, cntBipartite = 0;
	bool isExistNotBipartite = false;
	for(i=0;i<n;i++){
		if(!isVisited[i]){
			cnt++;
			
			dfs(i);	

			if(isBipartite(i)){
				cntBipartite++;
			}else{
				isExistNotBipartite = true;
			}
		}
		
	}
	if(isExistNotBipartite){
		printf("%d\n",cnt-1);
	}else{
		printf("%d\n",cnt);
	}
	// printf("cnt: %d cntBipartite; %d\n",cnt,cntBipartite);
	// printf("%d\n",cnt-1+cntBipartite);

	return 0;
};