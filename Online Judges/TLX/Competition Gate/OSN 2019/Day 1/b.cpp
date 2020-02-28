#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000L
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
typedef pair<ll,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;
ll biaya[maxn];

struct pasangan {
	int awal, akhir, harga;
};

bool cmp(pasangan a, pasangan b){
	if(a.awal == b.awal){return a.akhir < b.akhir;}
	return a.awal < b.awal;
}

vector<vii> adj;

ii st[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n+1;}

ii combine(ii ans1, ii ans2) {
	ll ansMin = min(ans1.first, ans2.first);
	int idxMin = ans2.first == ansMin ? ans2.second : ans1.second;
	return ii(ansMin, idxMin);
}

ii query(int node, int l, int r, int i, int j) {
	if(r < i || l > j) {return ii(inf,-1);}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i, j);
	ii ans2 = query(right(node), mid+1, r, i, j);
	return combine(ans1, ans2);
}

void update(int node, int l, int r, int idx, ll val) {
	if(r < idx || l > idx){return;}
	if(l == idx && l == r){st[node] = ii(val, idx); return;}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx, val);
	st[node] = combine(st[left(node)], st[right(node)]);
}

int main(){
	int n,m,i,j,s;
	
	scanf("%d %d %d",&n,&m,&s);
	for(i=1;i<=n;i++){
		biaya[i] = s;
		biaya[i] += biaya[i-1];
		// printf("biaya[%d]: %lld\n",i,biaya[i]);
	}
	pasangan p[maxn];
	adj.assign(maxn, vii());
	for(i=0;i<m;i++){
		scanf("%d %d %d",&p[i].awal, &p[i].akhir, &p[i].harga);
		adj[p[i].awal].pb(ii(p[i].akhir, p[i].harga));
		// for(j=p[i].awal;j<=p[i].akhir;j++){
		// 	adj[j].pb(p[i].harga);	
		// }
	}
	sort(p, p+m, cmp);
	int akhir[maxn];
	memset(akhir, 0, sizeof akhir);
	ll kurang = 0;
	for(i=1;i<=n;i++) {
		//cari minimal dari sini
		for(j=0;j<adj[i].size();j++){
			ii v = adj[i][j];
			int akhir = v.first, harga = v.second;
			ii minim = query(1,1,n,1,i-1);
			ll ans = minim.first, idx = minim.second;
			ll biayaAsli = ans + ((idx-1)*(ll)s);
			for(int l=i;l<=akhir;l++){
				biaya[l] = min(biaya[l], (ll)harga + biayaAsli + (ll)s*(ll)(i-idx-1));	
			}	
			
			if(i == 1){
				for(int k=i;k<=akhir;k++){
					biaya[k] = min(biaya[k], (ll)harga);
				}
			}
		}
		if(!adj[i].size()) {
			for(j=1;j<i;j++){
				biaya[i] = min(biaya[i], biaya[j] + (ll)s*(ll)(i-j));
				// printf("biaya[%d]: %lld biaya[%d]: %lld\n",i, biaya[i],j,biaya[j]);	
				
			}
		}

		update(1,1,n,i,biaya[i] - kurang);

		kurang += s;
		// printf("%lld ",biaya[i]);
	}
	// for(i=1;i<=n;i++){
	// 	printf("biaya[%d]: %lld\n",i, biaya[i]);
	// }
	// printf("\n");
	printf("%lld\n",biaya[n]);
	return 0;
};