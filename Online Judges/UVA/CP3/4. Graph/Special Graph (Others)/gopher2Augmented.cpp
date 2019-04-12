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

vector<vi> AdjList;
const int maxn = 110;

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
	int n,m,waktu,v;
	int i,j;
	double x1[maxn],y1[maxn],x2[maxn],y2[maxn];
	while(scanf("%d %d %d %d",&n,&m,&waktu,&v)!=EOF) {
		AdjList.assign(n+m+2,vi());
		double jarakMaks = (double)waktu*v;
		for(i=0;i<n;i++){
			scanf("%lf %lf",&x1[i],&y1[i]);
		}
		for(i=0;i<m;i++){
			scanf("%lf %lf",&x2[i],&y2[i]);
		}

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				double jarak = hypot(x1[i] - x2[j], y1[i] - y2[j]);
				if(fabs(jarak-jarakMaks) < eps || jarak < jarakMaks) {
					AdjList[i].pb(n+j);
				}
			}
		}
		int mcbm = 0;
		match.assign(n+m+2,-1);
		for(i=0;i<n;i++){
			vis.assign(n,0);
			mcbm+=Aug(i);
		}
		
		printf("%d\n", n-mcbm);
	}
	
	return 0;
};