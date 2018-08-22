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
double ans[maxn];
bool isVisited[maxn];
int ukuran[maxn];

vector<vi> AdjList;

int dfs(int node){
	int ans = 1;
	isVisited[node] = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]){
			ans += dfs(v);
		}
	}
	return ukuran[node] = ans;
}

int main(){
	int n = 3;
	scanf("%d",&n);
	int i,j,k;
	
	AdjList.assign(n+1, vi());
	int p[maxn];
	for(i=2;i<=n;i++){
		int parent;
		scanf("%d",&parent);
		p[i] = parent;
		AdjList[parent].pb(i);
	}

	
	memset(isVisited, false, sizeof isVisited);
	dfs(1);
	
	ans[1] = 1.0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int front = q.front(); q.pop();
		int ukuranTotal = 0;
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			ukuranTotal+=ukuran[v];
		}
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			int ukuranLain = ukuranTotal - ukuran[v];
			ans[v] = ans[p[v]] + 1.0 + (double)ukuranLain / 2.0;
			q.push(v);
		}
	}
	for(i=1;i<=n;i++){
		if(i>1){printf(" ");}
		printf("%.9lf",ans[i]);
	}
	printf("\n");
	return 0;
};