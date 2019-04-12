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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e4 + 4;

vector<vi> AdjList, back;
int dfs_num[maxn], dfs_low[maxn];
bool isVisited[maxn];
int counter = 0;
vector<int> listNode;
int numScc = 0;
int id[maxn];
vi listCycle;
bool isReachable[maxn];

void dfs(int n) {
	dfs_low[n] = dfs_num[n] = counter++;
	isVisited[n] = true;
	listNode.pb(n);
	int i,j;
	for(i=0;i<AdjList[n].size();i++){
		int v = AdjList[n][i];
		if(dfs_num[v] == -1){
			dfs(v);
		}
		if(isVisited[v]){
			dfs_low[n] = min(dfs_low[n], dfs_low[v]);
		}
	}
	if(dfs_low[n] == dfs_num[n]){
		// printf("scc: %d -> ",numScc);
		vi listBil;
		while(1){

			int bil = listNode.back(); listNode.pop_back();
			listBil.pb(bil);
			id[bil] = numScc;
			isVisited[bil] = false;
			// printf("%d ",bil);
			if(bil == n){break;}
		}
		if(listBil.size() > 1){
			for(i=0;i<listBil.size();i++){
				listCycle.pb(listBil[i]);
				// printf("dipush: %d\n",listBil[i]);
			}
		}
		numScc++;
		// printf("\n");
	}
}

void dfs1(int n){
	isReachable[n] = true;
	// printf("%d true\n",n);
	for(int i=0;i<back[n].size();i++){
		int v = back[n][i];
		if(!isReachable[v]){
			dfs1(v);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	memset(dfs_num, -1, sizeof dfs_num);
	memset(isVisited, false, sizeof isVisited);
	map<string, int> mapper;

	AdjList.assign(maxn, vi()); back.assign(maxn, vi());
	memset(id, -1, sizeof id);
	int cnt = 0;
	for(i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		if(mapper.find(a) == mapper.end()){
			mapper[a] = cnt++;
		}
		if(mapper.find(b) == mapper.end()){
			mapper[b] = cnt++;
		}
		int idx1 = mapper[a], idx2 = mapper[b];
		AdjList[idx1].pb(idx2);
		back[idx2].pb(idx1);
		// printf("idx1 => idx2: %d %d\n",idx1, idx2);
	}

	for(i=0;i<cnt;i++){
		if(dfs_num[i] == -1){
			dfs(i);
		}
	}
	int ukuran = listCycle.size();
	
	memset(isReachable, false, sizeof isReachable);
	for(i=0;i<ukuran;i++){
		int node = listCycle[i];
		if(!isReachable[node]){
			dfs1(node);
		}
	}
	sort(listCycle.begin(), listCycle.end());

	string kata;
	while(cin>>kata) {
		int idx = mapper[kata];
		cout<<kata<<" ";
		if(isReachable[idx]){printf("safe\n");}
		else{printf("trapped\n");}
	}

	return 0;
};