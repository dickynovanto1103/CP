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

int left(int n){return 2*n;}
int right(int n){return 2*n+1;}

const int maxn = 1e5 + 4;
int a[maxn];
int st[4*maxn];

vector<vi> adj;

void build(int node, int l, int r){
	if(l == r){
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		st[node] = max(st[left(node)], st[right(node)]);
	}
}

int query(int node, int l, int r, int i, int j) {
	if(r < i || l > j){return -inf;}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	return max(query(left(node), l, mid, i, j), query(right(node), mid+1, r, i, j));
}

int n, m;

ll solve(int l, int r, int tambah) {
	if(l > r){return 0;}
	int maks = query(1,1,n,l, r);
	int selisih = m - (maks + tambah);
	// printf("maks: %d selisih: %d\n",maks, selisih);
	int kiri = lower_bound(adj[maks].begin(), adj[maks].end(), l) - adj[maks].begin();
	ll tot = selisih;
	int tempIdx = l;
	for(int i=kiri;i<adj[maks].size();i++){
		int idx = adj[maks][i];
		if(idx > r){break;}
		// printf("cek solve %d %d\n",tempIdx, idx-1);
		tot += solve(tempIdx, idx-1, tambah + selisih);

		tempIdx = idx+1;
	}
	tot += solve(tempIdx, r, tambah + selisih);

	return tot;
}


int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&m);
		adj.assign(m+1, vi());
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			adj[a[i]].pb(i);
		}
		build(1,1,n);
		printf("%lld\n",solve(1,n,0));
	}
	return 0;
};