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

const int maxn = 2e5 + 5;

vector<vi> menyerang, diserang;
set<int> kernel, other;
bool isVisited[maxn];

void dfs(int node, int step) {
	if(step%2==1){
		other.insert(node);
	}else{
		kernel.insert(node);
	}
	isVisited[node] = true;
	for(int i=0;i<menyerang[node].size();i++){
		int v = menyerang[node][i];
		if(!isVisited[v]) {
			dfs(v,step+1);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	diserang.assign(maxn,vi()); menyerang.assign(maxn, vi());
	int indegree[maxn];
	memset(indegree,0,sizeof indegree);
	for(i=1;i<=n;i++){
		int bil;
		scanf("%d",&bil);
		diserang[bil].pb(i);
		menyerang[i].pb(bil);
		indegree[bil]++;
	}
	for(i=n+1;i<=(2*n);i++){
		int bil;
		scanf("%d",&bil);
		diserang[bil].pb(i);
		menyerang[i].pb(bil);
		indegree[bil]++;
	}
	
	memset(isVisited, false,sizeof isVisited);

	queue<int> q, q1;
	for(i=1;i<=(2*n);i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()) {
		int front = q.front(); q.pop();

		isVisited[front] = true;
		kernel.insert(front);
		for(i=0;i<menyerang[front].size();i++){
			int v = menyerang[front][i];
			if(isVisited[v]){continue;}
			isVisited[v] = true;
			other.insert(v);
			indegree[v]--;
			for(j=0;j<menyerang[v].size();j++){
				int diserangV = menyerang[v][j];
				indegree[diserangV]--;
				if(indegree[diserangV]==0 && !isVisited[diserangV]){
					q.push(diserangV);
				}
			}
		}
	}

	for(i=1;i<=2*n;i++){
		if(!isVisited[i]) {
			dfs(i,0);
		}
	}

	set<int>::iterator it;
	int cnt = 0;
	for(it=kernel.begin();it!=kernel.end();it++){
		if(cnt){printf(" ");}
		cnt++;
		printf("%d",*it);
	}
	printf("\n");

	return 0;
};