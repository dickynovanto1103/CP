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

const int maxn = 55;

vector<vi> AdjList;
bool isVisited[maxn];

int dfs(int n) {
	isVisited[n] = true;
	int cnt = 1;
	for(int i=0;i<AdjList[n].size();i++){
		int v = AdjList[n][i];
		if(!isVisited[v]){
			cnt += dfs(v);
		}
	}
	return cnt;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	memset(isVisited, false, sizeof isVisited);
	ll ans = 1;
	for(i=1;i<=n;i++){
		//coba dari sini brp
		if(!isVisited[i]){
			ans *= (1LL<<(dfs(i)-1));
		}
	}
	printf("%lld\n",ans);
	return 0;
};