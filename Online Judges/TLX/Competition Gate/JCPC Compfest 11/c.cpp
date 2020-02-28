#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 10000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const ll *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
int c[100002];
vector<pii> adj[100002];
vector<int> tele[100002];
ll dist0[100002];
ll distn[100002];

void fill_dist(ll *dist, int node) {
	for(i=0;i<n;i++){
		dist[i] = inf;
	}
	dist[node] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push({0, node});
	while(!pq.empty()){
		pair<ll, int> tmp = pq.top();
		pq.pop();
		
		if(dist[tmp.se] < -tmp.fi) continue;

		for(const pii & x : adj[tmp.se]) {
			if(dist[x.fi] != -1 && dist[x.fi] > -tmp.fi + x.se) {
				dist[x.fi] = -tmp.fi + x.se;
				pq.push({-dist[x.fi], x.fi});
			}
			else if (dist[x.fi] == -1){
				dist[x.fi] = -tmp.fi + x.se;
				pq.push({-dist[x.fi], x.fi});
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<m;++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a, --b;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}
	for(int i=0;i<n;++i){
		scanf("%d", &t);
		for(int j=0;j<t;++j){
			int a;
			scanf("%d", &a);
			tele[--a].pb(i);
		}
	}
	for(int i=0;i<k;++i){
		scanf("%d", c+i);
	}
	fill_dist(dist0, 0);
	fill_dist(distn, n-1);
	ll ans = dist0[n-1];
	for(int i=0;i<k;++i){
		if(tele[i].size() <= 1) continue;
		vector<pair<ll, int>> x0;
		vector<pair<ll, int>> xn;
		for(int x : tele[i]){
			x0.pb({dist0[x], x});
			xn.pb({distn[x], x});
		}
		sort(x0.begin(), x0.end());
		sort(xn.begin(), xn.end());
		if(x0[0].se == xn[0].se) {
			ans = min(ans, c[i] + x0[0].fi +  xn[1].fi);
			ans = min(ans, c[i] + x0[1].fi +  xn[0].fi);
		}
		else {
			ans = min(ans, c[i] + x0[0].fi +  xn[0].fi);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

/* Template Function */
void printArray(const ll * a, int n){
	for(int i=0;i<n;++i){
		printf("%lld ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}