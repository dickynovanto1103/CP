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

const int maxn = 2e3 + 3;

vector<vi> AdjList;

int label[maxn];

vi preorder, postorder;

void dfsPreorder(int node, int parent){
	preorder.pb(node);
	
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v != parent){
			dfsPreorder(v, node);
		}
	}
}

void dfsPostorder(int node, int parent){
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v != parent){
			dfsPostorder(v, node);
		}
	}
	postorder.pb(node);
}

bool isVisited[maxn];
vector<vi> terkait;

void dfs(int node, int warna){
	label[node] = warna;
	isVisited[node] = true;
	for(int i=0;i<terkait[node].size();i++){
		int v = terkait[node][i];
		if(!isVisited[v]){
			dfs(v, warna);
		}
	}
}

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&k);
		AdjList.assign(n+1,vi());

		for(i=1;i<=n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(a==0 && b==0){continue;}
			if(a==0 || b==0){
				if(a==0){
					AdjList[i].pb(b);
					AdjList[b].pb(i);
				}else{
					AdjList[i].pb(a);
					AdjList[a].pb(i);
				}
			}else{
				AdjList[i].pb(a);
				AdjList[a].pb(i);
				AdjList[i].pb(b);
				AdjList[b].pb(i);

			}
		}

		dfsPreorder(1,-1); dfsPostorder(1,-1);

		memset(label, -1, sizeof label);
		
		int warna = 1;
		bool sudahKomplit = false;

		terkait.assign(n+1,vi());
		for(i=0;i<n;i++){
			int node1 = preorder[i], node2 = postorder[i];
			terkait[node1].pb(node2); terkait[node2].pb(node1);
		}

		int daerah = 0;	
		memset(isVisited, false, sizeof isVisited);
		for(i=1;i<=n;i++){
			if(!isVisited[i]){
				dfs(i, warna);	
				daerah++;
				warna++;
				if(warna>k){warna = 1;}
			}
		}

		if(daerah>=k){
			for(i=1;i<=n;i++){
				if(i>1){printf(" ");}
				printf("%d",label[i]);
			}
			printf("\n");
		}else{
			printf("Impossible\n");
		}

		AdjList.clear();
		preorder.clear(); postorder.clear();
	}
	return 0;
};