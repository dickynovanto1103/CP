#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num;
int jumlahAnak[105];

void dfsAnak(int u){
	dfs_num[u] = visited;
	jumlahAnak[u]++;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v]==unvisited){
			dfsAnak(v);
			jumlahAnak[u]+=jumlahAnak[v];
		}
	}
}
int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	
	dfs_num.assign(n,unvisited);
	AdjList.assign(n,vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b); a--; b--; AdjList[a].push_back(b); AdjList[b].push_back(a);
	}
	//dfs nentukan jumlah dfs
	memset(jumlahAnak,0,sizeof jumlahAnak);
	for(i=0;i<n;i++){
		if(dfs_num[i]==unvisited){dfsAnak(i);}
	}
	int cnt = 0;
	for(i=1;i<n;i++){
		if(jumlahAnak[i]%2==0){cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
}