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

const int maxn = 3e5 + 5;

bool valid = true;

ll a[maxn];

void solve(int node, int p) {
	if(!valid){return;}
	int cntTidakTau = 0;
	ll sum = 0;
	if(adj[node].size() == 1 && node != 1){return;}
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == p){continue;}
		if(a[v]){
			sum += a[v];
		}else{
			cntTidakTau++;
		}
	}
	// printf("node: %d sum: %lld\n",node,sum);
	// printf("cntTidakTau: %d\n",cntTidakTau);
	if(sum <= 0){valid =false; return;}
	if(cntTidakTau == 0) {
		if(a[node]){
			if(a[node] != sum){
				// printf("ga valid\n");
				valid = false; return;
			}	
		}else{
			a[node] = sum;
		}
		// printf("a[%d]: %lld\n",node, a[node]);
		for(int i=0;i<adj[node].size();i++){
			int v = adj[node][i];
			if(v == p){continue;}
			solve(v, node);
		}
	}else if(cntTidakTau == 1) {
		if(a[node]) {
			ll ans = a[node] - sum;
			if(ans <= 0){valid = false; return;}
			// printf("ans: %lld a[%d]: %lld sum: %lld\n",ans,node,a[node],sum);
			for(int i=0;i<adj[node].size();i++){
				int v = adj[node][i];
				if(v == p){continue;}
				if(!a[v]){
					a[v] = ans;
					break;
				}
			}
			for(int i=0;i<adj[node].size();i++){
				int v = adj[node][i];
				if(v == p){continue;}
				solve(v, node);
			}
		}else{
			
			for(int i=0;i<adj[node].size();i++){
				int v = adj[node][i];
				if(v == p){continue;}
				solve(v, node);
			}
			ll tot = 0;
			for(int i=0;i<adj[node].size();i++){
				int v = adj[node][i];
				if(v == p){continue;}
				tot += a[v];
			}
			a[node] = tot;
		}
	}else{
		if(a[node]){
			if(sum + cntTidakTau == a[node]){
				for(int i=0;i<adj[node].size();i++){
					int v = adj[node][i];
					if(v == p){continue;}
					if(!a[v]){a[v] = 1;}
				}
				for(int i=0;i<adj[node].size();i++){
					int v = adj[node][i];
					if(v == p){continue;}
					solve(v, node);
				}
			}else{
				for(int i=0;i<adj[node].size();i++){
					int v = adj[node][i];
					if(v == p){continue;}
					solve(v,node);
				}
			}
		}else{
			for(int i=0;i<adj[node].size();i++){
				int v = adj[node][i];
				if(v == p){continue;}
				solve(v, node);
			}
			ll tot = 0;
			for(int i=0;i<adj[node].size();i++){
				int v = adj[node][i];
				if(v == p){continue;}
				tot += a[v];
			}
			a[node] = tot;
		}
	}
}

int parent[maxn];

bool check(int node, int p) {
	ll sum = 0;
	if(adj[node].size() == 1 && node != 1){return true;}
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v == p){continue;}
		sum += a[v];
	}
	return sum == a[node];
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	adj.assign(n+1,vi());

	for(i=2;i<=n;i++){
		int p;
		scanf("%d",&p);
		parent[i] = p;
		adj[p].pb(i); adj[i].pb(p);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	solve(1,-1);
	if(!valid){
		printf("impossible\n");
		// printf("sini\n");
		return 0;
	}
	for(i=1;i<=n;i++){
		if(a[i] <= 0){
			printf("impossible\n");
			// printf("i: %d\n",i);
			return 0;
		}else{
			if(!check(i, parent[i])){
				printf("impossible\n");
				// printf("i: %d\n",i);
				return 0;
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("%lld\n",a[i]);
		assert(a[i] > 0);
	}
	return 0;
};