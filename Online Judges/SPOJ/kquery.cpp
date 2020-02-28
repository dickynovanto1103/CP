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

const int maxn = 3e4 + 4;

int cnt[maxn];
int st[4*maxn];

struct quer {
	int l, r, val, idx;
};

bool cmp(quer a, quer b){
	return a.val < b.val;
}

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r) {
	if(l == r) {
		st[node] = cnt[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		st[node] = st[left(node)] + st[right(node)];
	}
}

void update(int node, int l, int r, int idx, int val) {
	// printf("update: l: %d r: %d idx: %d val: %d\n",l,r,idx,val);
	if(r < idx || l > idx){return;}
	if(l == idx && l == r) {
		st[node] = val;
		// printf("l: %d r; %d val: %d\n", l,r,val);
	}else{
		int mid = (l+r)/2;
		update(left(node), l, mid, idx, val);
		update(right(node), mid+1, r, idx, val);
		st[node] = st[left(node)] + st[right(node)];
	}
}

int query(int node, int l, int r, int i, int j) {
	if(r < i || l > j){return 0;}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i, j);
	return ans1 + ans2;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	ii pas[maxn];
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		pas[i].first = a[i]; pas[i].second = i;
		cnt[i] = 1;
	}
	build(1,1,n);
	// printf("test: %d\n",query(1,1,n,1,n));
	sort(pas+1, pas+n+1);
	int que;
	scanf("%d",&que);
	int ans[200010];
	quer q[200010];
	for(i=0;i<que;i++){
		int l, r, val;
		scanf("%d %d %d",&q[i].l,&q[i].r,&q[i].val);
		q[i].idx = i;
	}
	sort(q,q+que,cmp);
	int id = 1;
	for(i=0;i<que;i++) {
		int l = q[i].l, r = q[i].r, val = q[i].val, idx = q[i].idx;
		while(id <= n && pas[id].first <= val){
			// printf("pas[%d].first: %d\n",id, pas[id].first );
			int idxArray = pas[id].second;
			update(1,1,n,idxArray,0);
			// printf("update idxArray; %d\n",idxArray );
			id++;
		}
		ans[idx] = query(1,1,n,l,r);
		// printf("ans[%d]: %d l: %d r: %d\n",idx, ans[idx],l,r );
	}
	for(i=0;i<que;i++){
		printf("%d\n", ans[i]);
	}
	return 0;
};