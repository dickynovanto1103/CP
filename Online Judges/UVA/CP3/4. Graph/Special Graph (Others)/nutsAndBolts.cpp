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

const int maxn = 510;

vector<vi> AdjList;
vi match, vis;

int Aug(int node) {
	if(vis[node]){return 0;}//mencegah siapa tau dia balik
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1;
		}
	}
	return 0; //no matching
}

int AugmentedPathAlgo(int banyakNodeKiri) {
	match.assign(maxn+maxn,-1);
	int mcbm = 0;
	for(int i=0;i<banyakNodeKiri;i++) {
		vis.assign(banyakNodeKiri, 0);
		int ans = Aug(i);
		// printf("i: %d ans sekarang: %d\n",i,ans);
		mcbm+=ans;
	}
	return mcbm;
}

int main(){
	int tc,i,j;
	int n,m;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ",tt);

		scanf("%d %d",&n,&m);
		// printf("n: %d m: %d\n",n,m);
		AdjList.assign(n+m+2,vi());
		for(i=0;i<n;i++){
			for(j=0;j<m;j++) {
				int bil;
				scanf("%d",&bil);
				if(bil==1){
					AdjList[i].pb(j+n);
					// printf("i: %d dipush: %d\n",i,j+n);
				}
			}
		}
		int ans = AugmentedPathAlgo(n);
		printf("a maximum of %d nuts and bolts can be fitted together\n",ans);
		AdjList.clear(); match.clear(); vis.clear();
	}

	return 0;
};