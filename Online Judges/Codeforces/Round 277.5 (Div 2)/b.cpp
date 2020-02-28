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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> adj;
const int maxn = 110;

vi match, vis;

int Aug(int node){
	if(vis[node]){return 0;}
	vis[node] = 1;
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1;
		}
	}
	return 0;
}

int main(){
	int n,m,i,j;
	scanf("%d",&n);
	int a[maxn], b[maxn];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	scanf("%d",&m);
	for(i=0;i<m;i++){scanf("%d",&b[i]);}
	adj.assign(2*maxn,vi());
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(abs(a[i] - b[j]) <= 1) {
				adj[i].pb(n+j);
			}
		}
	}
	int mcbm = 0;
	match.assign(2*maxn, -1);
	for(i=0;i<n;i++){
		vis.assign(n+1, 0);
		mcbm += Aug(i);
	}
	printf("%d\n",mcbm);
	return 0;
};