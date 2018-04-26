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

int n;
vi child[10002], graf[10002];
int luas[10002];
bool vis[10002];

int dfs(int v){
	luas[v] = 0;
	for(int& a:graf[v]){
		if(vis[a])
			continue;
		vis[a] = true;
		child[v].pb(a);
		luas[v] += 1 + dfs(a);
	}
	return luas[v];
}

int main(){
	memset(vis, false, sizeof vis);
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	int maxans = 0;
	int minans = 0;
	vis[0] = true;
	dfs(0);
	for(int i=0;i<=n;i++){
		if(graf[i].size()<=1)
			continue;
		std::vector<int> reg;
		int sum = n;
		for(int& v : child[i]){
			sum -= luas[v]+1;
			reg.pb(luas[v]+1);
		}
		if(sum>0)
			reg.pb(sum);
		sort(reg.begin(), reg.end());
		reverse(reg.begin(), reg.end());
		int maxluas = n*n;
		for(int j=2;j<reg.size();j++){
			maxluas -= reg[j]*reg[j];
		}
		int minluas = maxluas - (reg[0]+reg[1])*(reg[0]+reg[1]);
		maxluas -= reg[0]*reg[0] + reg[1]*reg[1];
		minluas /= 2;
		maxluas /= 2;
		if(maxans < maxluas){
			maxans = maxluas;
			minans = minluas;
		}
		else if(maxans == maxluas){
			minans = min(minans, minluas);
		}
	}
	printf("%d %d\n", maxans, minans);
	return 0;
};