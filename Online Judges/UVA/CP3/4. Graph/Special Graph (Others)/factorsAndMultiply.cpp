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

const int maxn = 110;

vi match, vis;
vector<vi> AdjList;

int Aug(int node) {
	if(vis[node]) {return 0;}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1;
		}
	}
	return 0;
}

int augmentedAlgo(int banyakNodeKiri, int banyakNodeTotal) {
	match.assign(banyakNodeTotal, -1);
	int mcbm = 0;
	for(int i=0;i<banyakNodeKiri;i++) {
		vis.assign(banyakNodeKiri,0);
		mcbm+=Aug(i);
	}
	return mcbm;
}

int main(){
	int tc,tt,i,j,n,m;
	int a[110], b[110];
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case %d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		scanf("%d",&m);
		for(i=0;i<m;i++){scanf("%d",&b[i]);}

		AdjList.assign(maxn+maxn,vi());

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i] == 0){
					if(b[j] == 0){
						AdjList[i].pb(j+n);
					}
					continue;
				}
				if((b[j] % a[i]) == 0) {
					AdjList[i].pb(j+n);
				}
			}
		}

		int ans1 = augmentedAlgo(n,n+m);

		// AdjList.assign(maxn+maxn,vi());

		int ans2 = inf;

		printf("%d\n",min(ans1,ans2));
	}
	return 0;
};