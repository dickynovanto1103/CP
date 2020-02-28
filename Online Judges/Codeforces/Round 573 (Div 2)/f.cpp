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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

bool cmp(ii a, ii b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second > b.second;
}

int bit[maxn];

int query(int idx) {
	int i,j;
	int ans = 0;
	for(i=idx;i>=1;i-=(i&-i)){
		ans += bit[i];
	}
	return ans;
}

void update(int idx, int val) {
	int i,j;
	for(i=idx;i<maxn;i+=(i&-i)){
		bit[i] += val;
	}
}

vector<vi> adj;

int getSebelum(int sebelum, int idx) {
	int sekarang = query(idx);
	int prev = query(sebelum);
	return sekarang - prev;
}

int getSetelah(int idx) {
	int ne = query(maxn-1);
	int sekarang = query(idx-1);
	return ne - sekarang;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	ii a[maxn];
	int x[maxn], y[maxn];
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].first, &a[i].second);
		x[i] = a[i].first;
		y[i] = a[i].second;
	}
	sort(x, x+n);
	sort(y, y+n);
	map<int,int> mapper;
	int idx = 1;

	for(i=0;i<n;i++){
		// printf("i: %d\n",i);
		if(mapper.find(x[i]) == mapper.end()) {
			mapper[x[i]] = idx++;
			// printf("map %d ke %d\n",x[i], idx-1);
		}
	}

	map<int,int> mapperY;
	idx = 1;

	for(i=0;i<n;i++){
		if(mapperY.find(y[i]) == mapperY.end()) {
			mapperY[y[i]] = idx++;
		}
	}

	adj.assign(maxn, vi());

	for(i=0;i<n;i++){
		ii pas = a[i];
		int x = pas.first, y = pas.second;
		int idxX = mapper[x], idxY = mapperY[y];
		adj[idxY].pb(idxX);
	}

	for(i=0;i<maxn;i++){
		sort(adj[i].begin(), adj[i].end());
	}

	sort(a, a+n, cmp);
	int cnt = 0;
	int cur = -inf;
	ll ans = 0;
	bool vis[maxn];
	memset(vis, false, sizeof vis);

	for(i=0;i<n;i++){
		ii pas = a[i];
		// printf("pas: %d %d\n",pas.first, pas.second);
		if(cur != pas.second) {
			int idxY = mapperY[pas.second];
			ll ukuran = adj[idxY].size();
			// ans += (ukuran*(ukuran+1)/2LL); //untuk 1 levelnya
			// printf("idxY: %d ukuran: %lld\n",idxY, ukuran);
			for(j=0;j<adj[idxY].size();j++){
				int now = adj[idxY][j];
				if(!vis[now]) {
					vis[now] = true;
					update(now, 1);
				}
			}
			for(j=0;j<adj[idxY].size();j++){
				int prev = (j == 0 ? 0 : adj[idxY][j-1]);
				int now = adj[idxY][j];

				// printf("prev: %d now: %d\n",prev, now);
				int nilaiPrev = getSebelum(prev, now);
				int nilaiNext = getSetelah(now);
				// printf("nilaiPrev: %d nilaiNext: %d\n",nilaiPrev, nilaiNext);
				ans += ((ll)nilaiPrev*(ll)nilaiNext);
			}
			// int akhirBanget = query(maxn-1) - query(adj[idxY][ukuran-1]);
			// int awalBanget = query(adj[idxY][0]);
			// printf("awalBanget: %d akhirBanget: %d\n",awalBanget, akhirBanget);
			// ans += ((ll)awalBanget*(ll)akhirBanget);
			// ans -= ukuran;
		}
		cur = pas.second;
	}
	printf("%lld\n",ans);
	return 0;
};