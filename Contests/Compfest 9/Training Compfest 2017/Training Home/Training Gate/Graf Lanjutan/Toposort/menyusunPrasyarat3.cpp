#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define explored 2
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vi> AdjList;
vi dfs_num,ans;
set<int> listNode;
set<int>::iterator it;
int indegree[50010];
bool foundCycle;
void dfs(int a){
	if(foundCycle){return;}
	dfs_num[a] = explored;
	for(int i=0;i<AdjList[a].size();i++){
		int v = AdjList[a][i];
		if(dfs_num[v]==unvisited){dfs(v);}
		else if(dfs_num[v]==explored){foundCycle = true;}
	}
	dfs_num[a] = visited;
}

void toposort(){
	while(!listNode.empty()){
		it = listNode.begin();
		int bil = *it;
		ans.pb(bil); listNode.erase(it);
		
		for(int j=0;j<AdjList[bil].size();j++){
			int v = AdjList[bil][j];
			indegree[v]--;
			if(indegree[v]==0){listNode.insert(v); }
		}
		
	}
	return;
}

int main(){
	//freopen("input.txt","r",stdin);
	int n,i,j,m;
	//vi dfs_num;	
	string kata1,kata2,kata;
	scanf("%d %d",&n, &m);
	
	dfs_num.assign(n+1,unvisited); AdjList.assign(n+1,vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].push_back(b); indegree[b]++;
	}
	
	//cek ada cycle atau ga
	foundCycle = false;	
	for(i=1;i<=n;i++){
		if(dfs_num[i]==unvisited){dfs(i);}
		if(foundCycle) break;
	}
	//printf("test\n");
	if(foundCycle){
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("-1");
		}
		printf("\n");
	}
	else{
		
		for(i=1;i<=n;i++){
			if(indegree[i]==0){listNode.insert(i); }
		}
		
		toposort();
		int ukuran = ans.size();
		for(i=0;i<ukuran;i++){
			
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");

	}

	return 0;
}