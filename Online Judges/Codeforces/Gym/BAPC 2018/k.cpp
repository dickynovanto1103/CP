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

const int maxn = 1e5 + 5;

vector<vi> AdjList, listRoot;
int par[maxn], cnt[maxn], firstRoot[maxn];


void dfs(int node, int p) {
	int i,j;
	int ukuran = AdjList[node].size();
	for(i=0;i<ukuran;i++){
		int v = AdjList[node][i];
		if(v != p){
			par[v] = par[node];
			dfs(v, node);
		}
	}
	if(ukuran == 1){
		listRoot[par[node]].pb(node);
		cnt[par[node]]++;
	}
}

int main(){
	int n,root;
	int i,j;
	scanf("%d %d",&n,&root);
	AdjList.assign(maxn, vi());
	listRoot.assign(maxn, vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}

	for(i=0;i<AdjList[root].size();i++){
		int v = AdjList[root][i];
		par[v] = v;
		dfs(v, root);
	}
	priority_queue<ii> pq;

	memset(firstRoot, -1, sizeof firstRoot);

	for(i=0;i<n;i++){
		// printf("par[%d]: %d cnt[%d]: %d: ",i,par[i],i,cnt[i]);
		if(cnt[i])
			pq.push(ii(cnt[i], par[i]));
		if(listRoot[i].size() == 0){
			// printf("\n");
			continue;
		}
		firstRoot[i] = listRoot[i][0];
		// for(j=0;j<listRoot[i].size();j++){
		// 	printf("%d ",listRoot[i][j]);
		// }
		// printf("\n");
	}
	vii ans;

	while(pq.size() >= 2){
		// printf("halo\n");
		ii satu = pq.top(); pq.pop();
		ii dua = pq.top(); pq.pop();
		int idx1 = satu.second, ukuran1 = satu.first - 1;
		int idx2 = dua.second, ukuran2 = dua.first - 1;	
		int elemen1 = listRoot[idx1].back(); listRoot[idx1].pop_back();
		int elemen2 = listRoot[idx2].back(); listRoot[idx2].pop_back();
		ans.pb(ii(elemen1, elemen2));
		// printf("dipush: %d %d\n",elemen1, elemen2);
        if(ukuran1)
		    pq.push(ii(ukuran1, idx1));
        if(ukuran2)
            pq.push(ii(ukuran2, idx2));
	}

    if(pq.size() == 1){
		ii satu = pq.top(); pq.pop();
		int idx = satu.second, ukuran = satu.first;
		// printf("ukuran: %d\n",ukuran);
		for(i=0;i<ukuran-1;i+=2){
			// printf("dipush kedua: %d %d\n", listRoot[idx][i], listRoot[idx][i+1]);
			ans.pb(ii(listRoot[idx][i], listRoot[idx][i+1]));
		}
		ans.pb(ii(listRoot[idx][listRoot[idx].size() - 1], root));
	}

	int ukuran = ans.size();
	printf("%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}

	return 0;
};