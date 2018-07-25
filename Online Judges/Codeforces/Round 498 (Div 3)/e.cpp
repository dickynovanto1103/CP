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

vector<vi> AdjList;
int dp[maxn];

vi listUrutan;

int dfs(int node){
	int banyak = 1;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		listUrutan.pb(v);
		banyak+=dfs(v);
	}
	return dp[node] = banyak;
}

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	AdjList.assign(n+1,vi());
	for(i=2;i<=n;i++){
		int parent;
		scanf("%d",&parent);
		AdjList[parent].pb(i);
	}
	listUrutan.pb(1);
	dfs(1);

	int listIdx[maxn];

	for(i=0;i<listUrutan.size();i++){
		listIdx[listUrutan[i]] = i;
	}

	while(q--){
		int node, idx;
		scanf("%d %d",&node,&idx);
		if(idx > dp[node]){printf("-1\n");}
		else{
			int idxSelanjutnya = listIdx[node] + idx - 1;
			printf("%d\n",listUrutan[idxSelanjutnya]);
		}
	}
	
	return 0;
};