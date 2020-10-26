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
typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

vector<vi> adj;
const int maxn = 4e5 + 5;
ll leaf[maxn];
ll a[maxn];
ll maks[maxn];
ll selisih[maxn];

bool cmp(iii a, iii b){
	return a.first.second < b.first.second;
}

void solve(int node, int p){
	viii list; //iii(ii(selisih, maks), node)
	selisih[node] = 0;
	maks[node] = a[node];
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != p){
			solve(v, node);
			if(leaf[node] == 1){
				maks[node] += maks[v];
			}else{
				assert(leaf[node] > 0);
				//hitung maks[node] dari maks semua child, terus ditambah sama a[node] yang didistribute ke leaf[node]
				list.pb(iii(ii(selisih[v], maks[v]), v));
			}
		} else {
			assert(false);
		}
	}

	sort(list.begin(), list.end(), cmp);
	//hitung total selisih
	if(list.size() == 0){
		// printf("maks[%d]: %lld selisih[%d]: %lld\n",node, maks[node], node, selisih[node]);
		return;
	}
	ll totSelisih = list[0].first.first;
	ll maksSekarang = list[0].first.second;
	ll leafSekarang = leaf[list[0].second];
	// printf("node: %d leaf sekarang: %lld\n",list[0].second, leaf[list[0].second]);
	for(int i=1;i<list.size();i++){
		iii pas = list[i];
		ll diff = pas.first.first;
		ll maksimum = pas.first.second;
		ll titik = pas.second;

		// printf("totSelisih sekarang: %lld\n",totSelisih);
		totSelisih += diff;
		// printf("totSelisih jadi: %lld\n",totSelisih);
		ll selisihMaks = maksimum - maksSekarang;
		assert(selisihMaks >= 0);
		assert(leafSekarang >= 1);
		// printf("maksimum: %lld maksSekarang: %lld selisihMaks: %lld\n", maksimum, maksSekarang, selisihMaks);
		totSelisih += (leafSekarang * selisihMaks);
		// printf("totSelisih: %lld leafSekarang: %lld, selisihMaks: %lld\n",totSelisih, leafSekarang, selisihMaks);
		
		leafSekarang += leaf[titik];
		maksSekarang = max(maksSekarang, maksimum);
	}
	// printf("totSelisih: %lld\n",totSelisih);
	//fit a[node] into selisih first;
	ll minim = min(totSelisih, a[node]);
	totSelisih -= minim;
	a[node] -= minim;
	if(a[node]){
		assert(totSelisih == 0);
		//distribute among leaf[node]
		ll maksTambah = (a[node] + leaf[node] - 1) / leaf[node];
		// 7 / 3 = 3 2 2
		// 9 / 4 = 3 2 2 2
		ll jumlahMaks = a[node] % leaf[node];
		ll jumlahMinim = leaf[node] - jumlahMaks;
		maksSekarang += maksTambah;
		totSelisih = jumlahMinim;
	}
	maks[node] = maksSekarang;
	selisih[node] = totSelisih;
}

void solveLeaf(int node, int p){
	leaf[node] = (adj[node].size() == 0 ? 1 : 0);
	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(p != v){
			solveLeaf(v, node);
			leaf[node] += leaf[v];
		}
	}
}

int main(){
	int n,i,j;
	
	while(scanf("%d",&n) != EOF) {
		adj.assign(n+1, vi());
		memset(leaf, 0, sizeof leaf);
		memset(selisih, 0, sizeof selisih);
		memset(maks, 0, sizeof maks);
		
		for(i=2;i<=n;i++){
			int p;
			scanf("%d",&p);
			adj[p].pb(i);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		solveLeaf(1, -1);
		solve(1, -1);
		ll ans = 0;
		for(i=1;i<=n;i++){
			ans = max(ans, maks[i]);
		}
		printf("%lld\n",ans);
	}
	

	
	return 0;
};