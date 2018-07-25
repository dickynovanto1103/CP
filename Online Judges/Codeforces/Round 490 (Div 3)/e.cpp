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

const int maxn = 5010;

vector<vi> AdjList;

int ans = 0;

vector<vi> AdjListAns;

bool isVisited[maxn];

void dfs(int node){
	isVisited[node] = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]){
			dfs(v);
		}
	}
}

bool isDikunjungi[maxn];
int mapperBil[maxn];

void dfsCariGrup(int node, int idx) {
	isDikunjungi[node] = true;
	mapperBil[node] = idx;
	AdjListAns[idx].pb(node);
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isDikunjungi[v]) {
			dfsCariGrup(v, idx);
		}
	}
}

set<int> s;

void dfsJawaban(int node){
	// isVisited[node] = true;
	int idxBil = mapperBil[node];
	printf("idxBil: %d\n",idxBil);
	if(s.find(idxBil) != s.end()){
		printf("ada idxBil ans jd:%d\n",ans-1);
		s.erase(idxBil);
		ans--;
	}
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]){
			dfsJawaban(v);
		}
	}
}

int main(){
	int i,a,b;
	int V,E;
	int capital;
	scanf("%d %d %d",&V,&E,&capital);
	capital--;
	AdjList.assign(V,vi());
	AdjListAns.assign(V+10,vi());
	for(i=0;i<E;i++){
		scanf("%d %d",&a,&b);
		a--; b--;
		AdjList[a].pb(b);
	}
	memset(isVisited, false, sizeof isVisited);
	memset(isDikunjungi, false, sizeof isDikunjungi);
	dfs(capital);
	int j;
	
	int idx = 0;
	for(i=0;i<V;i++){
		if(!isDikunjungi[i]){
			dfsCariGrup(i, idx);
			idx++;
		}
	}

	// for(i=0;i<idx;i++){
	// 	printf("%d:",i);
	// 	for(j=0;j<AdjListAns[i].size();j++){
	// 		printf(" %d",AdjListAns[i][j]);
	// 	}
	// 	printf("\n");
	// }


	for(i=0;i<V;i++){
		if(!isVisited[i]) {
			int idxBil = mapperBil[i];
			ans++;
			printf("idxBil sekarang: %d\n",idxBil);
			for(j=0;j<AdjListAns[idxBil].size();j++){
				int v = AdjListAns[idxBil][j];
				if(!isVisited[v]){
					dfsJawaban(v);
				}
			}
			s.insert(idxBil);
			printf("idxBil %d diinsert\n",idxBil);
		}
	}
	printf("%d\n",ans);

	return 0;
};