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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int tin[maxn], tout[maxn], waktu, batasAtas;

vector<vi> up, AdjList;

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void dfs(int u, int p){
	int i;

	tin[u] = waktu++;
	
	up[u][0] = p;
	for(i=1;i<=batasAtas;i++){
		up[u][i] = up[up[u][i-1]][i-1];
	}

	for(i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(v!=p){
			dfs(v, u);
		}
	}

	tout[u] = waktu++;
}

int lca(int a, int b){
	if(isAncestor(a,b)){return a;}
	if(isAncestor(b,a)){return b;}
	for(int i=batasAtas;i>=0;i--){
		if(!isAncestor(up[a][i], b)) {
			a = up[a][i];
		}
	}
	return up[a][0];
}


void preprocess() {
	waktu = 1;
	batasAtas = ceil(log2(maxn));
	up.assign(maxn, vi(batasAtas+1));
	dfs(1,1);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(maxn, vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	preprocess();
	int q;
	scanf("%d",&q);
	while(q--) {
		int a,b;
		scanf("%d %d",&a,&b);
		vi listA, listB;
		for(i=0;i<a;i++){
			int bil;
			scanf("%d",&bil);
			listA.pb(bil);
		}
		for(i=0;i<b;i++){
			int bil;
			scanf("%d",&bil);
			listB.pb(bil);
		}
		int lcaA = listA[0];
		int lcaB = listB[0];
		for(i=0;i<a;i++){
			lcaA = lca(lcaA, listA[i]);
		}
		for(i=0;i<b;i++){
			lcaB = lca(lcaB, listB[i]);
		}
		if(lcaA == lcaB){
			printf("NO\n");
		}else{
			if(!isAncestor(lcaA, lcaB) && !isAncestor(lcaB, lcaA)) {
				printf("YES\n");
			}else{
				if(isAncestor(lcaA, lcaB) && !isAncestor(lcaB, lcaA)) {
					//lebih rendah yang lcaB
					//cek ada ga node A yang dibawah lcaB
					bool valid = true;
					for(i=0;i<a;i++){
						if(isAncestor(lcaB, listA[i])) {
							valid = false; break;
						}
					}
					if(valid){printf("YES\n");}
					else{printf("NO\n");}
				}else if(!isAncestor(lcaA, lcaB) && isAncestor(lcaB, lcaA)) {
					//lebih rendah lcaA
					//cek ada ga node B yang di bawah lca A
					bool valid = true;
					for(i=0;i<b;i++){
						if(isAncestor(lcaA, listB[i])) {
							valid = false; break;
						}
					}
					if(valid){printf("YES\n");}
					else{printf("NO\n");}
				}
			}
		}
	}
	return 0;
};