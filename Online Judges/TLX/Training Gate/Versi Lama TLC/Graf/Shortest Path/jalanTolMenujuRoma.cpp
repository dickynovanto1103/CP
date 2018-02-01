#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList, AdjTol;
const int maxn = 502;
int memo[maxn][2];
vi dfs_num;
int solve(int node, bool sudahTol){
	dfs_num[node] = visited;
	int i,cnt=0;
	if(memo[node][sudahTol]!=-1){return memo[node][sudahTol];}
	int ans = inf;
	for(i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i]
		if(dfs_num[v]==unvisited){
			cnt++;
			ans = min(ans,1+solve(v,sudahTol));
		}
	}
	if(!sudahTol){
		for(i=0;i<AdjTol[node].size();i++){
			int v = AdjList[node][i]
			if(dfs_num[v]==unvisited){
				cnt++;
				ans = min(ans,1+solve(v,true));
			}
		}
	}
	
	if(cnt)

}

int main() {
	int n,l,t,awal,akhir,i,j;
	scanf("%d %d %d %d %d",&n,&l,&t,&awal,&akhir);
	AdjList.assign(n,vi()); AdjTol.assign(n,vi()); dfs_num.assign(n,unvisited);
	int a,b;
	for(i=0;i<l;i++){
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	for(i=0;i<t;i++){
		scanf("%d %d",&a,&b);
		AdjTol[a].pb(b); AdjTol[b].pb(a);
	}
	int ans = solve(awal,false);
	return 0;
}