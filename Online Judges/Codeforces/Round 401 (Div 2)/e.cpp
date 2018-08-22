#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000
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

struct pasangan{
	int a, b, h;
};

const int maxn = 1e5 + 5;

bool cmp(pasangan a, pasangan b){
	if(a.b == b.b){return a.a > b.a;}
	return a.b > b.b;
}

bool cmpA(pasangan a, pasangan b){
	return a.a < b.a;
}

ll st[4*maxn];
ll dp[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l == r){
		st[node] = dp[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		st[node] = max(st[left(node)], st[right(node)]);
	}
}

ll query(int node, int l, int r, int i, int j){
	if(r < i || l>j){
		return -inf;
	}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	ll ans1 = query(left(node), l, mid, i, j);
	ll ans2 = query(right(node), mid+1, r, i,j);
	return max(ans1,ans2);
}

void update(int node, int l, int r, int idx, ll val){
	if(idx < l || idx > r){return;}
	if(idx == l && r == idx){
		st[node] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx, val);
	st[node] = max(st[left(node)], st[right(node)]);
}

int main(){
	int n,i,j;
	pasangan pas[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d %d %d",&pas[i].a,&pas[i].b,&pas[i].h);}
	sort(pas, pas+n, cmpA);
	map<int,int> mapperIdx;
	int cnt = 1;
	vi listBil;
	// listBil.pb(0);
	for(i=0;i<n;i++){
		int bil = pas[i].a;
		listBil.pb(bil);
		if(mapperIdx.find(bil) == mapperIdx.end()){
			mapperIdx[bil] = cnt++;
		}
	}
	sort(pas, pas+n, cmp);

	for(i=0;i<n;i++){
		int a = pas[i].a;
		int b = pas[i].b;
		int idxATerdekat = lower_bound(listBil.begin(), listBil.end(), b) - listBil.begin();
		idxATerdekat--;

		int aTerdekat = listBil[idxATerdekat];
		
		int idxA = mapperIdx[aTerdekat];
		
		ll maksSebelum = query(1,1,n,1,idxA);
		ll jumlahSekarang = maksSebelum + (ll)pas[i].h;
		
		int idxASekarang = mapperIdx[a];

		if(jumlahSekarang > dp[idxASekarang]){
			dp[idxASekarang] = jumlahSekarang;
			update(1,1,n,idxASekarang,dp[idxASekarang]);
		}
	}

	printf("%lld\n",*max_element(dp+1,dp+n+1));

	return 0;
};