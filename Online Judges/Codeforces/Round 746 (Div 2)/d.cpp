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

int n;
int ansAll = -1;

vector<vi> adj;
vi euler;

int askEdgesBetweenIdx(int a, int b) {
	set<int> s;
	set<int>::iterator it;
	for(int i=a;i<=b;i++){
		s.insert(euler[i]);
	}

	printf("? %d",int(s.size()));
	for(it=s.begin(); it!=s.end();it++){
		printf(" %d",*it);		
	}
	printf("\n");
	fflush(stdout);

	int ans;
	scanf("%d",&ans);
	return ans;
}

void askAll() {
	printf("? %d", n);
	for(int i=0;i<n;i++){
		printf(" %d",i+1);
	}
	printf("\n");
	fflush(stdout);

	scanf("%d",&ansAll);
	assert(ansAll != -1);
}

void dfs(int node, int par) {
	euler.pb(node);
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != par) {
			dfs(v, node);
			euler.pb(node);
		}
	}
}

int main(){
	scanf("%d",&n);
	adj.assign(n+1, vi());
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(1, -1);
	// for(int i=0;i<euler.size();i++){
	// 	printf("%d: %d\n", i, euler[i]);
	// }
	// puts("");

	askAll();

	int kiri = 0, kanan = int(euler.size()) - 1, mid;
	ii ansEdge = ii(-1, -1);
	while(kiri + 1 < kanan) {
		mid = (kiri + kanan) / 2;
		// printf("kiri: %d mid: %d\n", kiri, mid);
		int ans = askEdgesBetweenIdx(kiri, mid);
		if(ans < ansAll) {
			kiri = mid;
			ansEdge = ii(euler[mid], euler[kanan]);
		}else if(ans == ansAll){
			ansEdge = ii(euler[kiri], euler[mid]);
			kanan = mid;
		}else{
			exit(100);
		}
	}

	assert(ansEdge != ii(-1,-1));
	
	printf("! %d %d\n",ansEdge.first, ansEdge.second);
	fflush(stdout);
	return 0;
};