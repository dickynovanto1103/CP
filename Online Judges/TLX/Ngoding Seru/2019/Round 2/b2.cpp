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

const int maxn = 1511;
 
vector<vi> AdjList;

vi match, vis;

int Aug(int node) {
	if(vis[node]){return 0;}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1; // found 1 matching
		}
	}
	return 0; //no matching
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	AdjList.assign(maxn, vi());

	int nomorTim = n+1;
	for(i=1;i<=k;i++){
		int tim;
		scanf("%d",&tim);
		for(j=1;j<=tim;j++){
			for(int m=0;m<3;m++){
				int peserta;
				scanf("%d",&peserta);
				
				AdjList[peserta].pb(nomorTim);
			}
			nomorTim++;
		}
	}

	int mcbm = 0;
	match.assign(nomorTim+2,-1);
	for(i=1;i<=n;i++){
		vis.assign(n+1,0);
		mcbm+=Aug(i);
	}

	printf("%d\n",mcbm);



	return 0;
};