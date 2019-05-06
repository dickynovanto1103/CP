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
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;

pii tree[400004];
pii rtree[400004];
int p101[100002];
int p102[100002];
char s[100002];


void build(int l, int r, int pos){
	if(l == r){
		tree[pos] = {s[l] - '0' + 1, s[l] - '0' + 1};
		rtree[pos] = {s[l] - '0' + 1, s[l] - '0' + 1};
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, 2*pos+1);
	build(mid+1, r, 2*pos+2);
	int len1 = mid - l +1;
	int len2 = r - mid;
	tree[pos] = {
		((1LL*tree[2*pos+1].fi * p101[len2]) % mod1 + tree[2*pos+2].fi)% mod1,
		((1LL*tree[2*pos+1].se * p102[len2]) % mod2 + tree[2*pos+2].se)% mod2
	};
	rtree[pos] = {
		((1LL*rtree[2*pos+2].fi * p101[len1]) % mod1 + rtree[2*pos+1].fi)% mod1,
		((1LL*rtree[2*pos+2].se * p102[len1]) % mod2 + rtree[2*pos+1].se)% mod2
	};
}

void update(int l, int r, int pos, int idx, int val){
	if(l > idx || r < idx) return;
	if(l == r){
		tree[pos] = {val, val};
		rtree[pos] = {val, val};
		return;
	}
	int mid = (l+r)/2;
	update(l, mid, 2*pos+1, idx, val);
	update(mid+1, r, 2*pos+2, idx, val);
	int len1 = mid - l +1;
	int len2 = r - mid;
	tree[pos] = {
		((1LL*tree[2*pos+1].fi * p101[len2]) % mod1 + tree[2*pos+2].fi)% mod1,
		((1LL*tree[2*pos+1].se * p102[len2]) % mod2 + tree[2*pos+2].se)% mod2
	};
	rtree[pos] = {
		((1LL*rtree[2*pos+2].fi * p101[len1]) % mod1 + rtree[2*pos+1].fi)% mod1,
		((1LL*rtree[2*pos+2].se * p102[len1]) % mod2 + rtree[2*pos+1].se)% mod2
	};
}

pair<pii, pii> query(int l, int r, int pos, int ql, int qr){
	if(l > qr || r < ql) return {{0,0},{0,0}};
	if(l >= ql && r <= qr) return {tree[pos], rtree[pos]};
	int mid = (l+r)/2;
	pair<pii, pii> x = query(l, mid, 2*pos+1, ql, qr);
	pair<pii, pii> y = query(mid+1, r, 2*pos+2, ql, qr);
	int len1 = min(mid - l +1,  mid - ql + 1);
	int len2 = min(r - mid, qr - mid);
	if(mid >= qr){
		return x;
	}
	else if(mid+1 <= ql){
		return y;
	}
	return {
		{((1LL*x.fi.fi * p101[len2]) % mod1 + y.fi.fi)% mod1,
		((1LL*x.fi.se * p102[len2]) % mod2 + y.fi.se)% mod2},
		{((1LL*y.se.fi * p101[len1]) % mod1 + x.se.fi)% mod1,
		((1LL*y.se.se * p102[len1]) % mod2 + x.se.se)% mod2}
	};
}

int main(){
	memset(tree, 0, sizeof tree);
	p102[0] = p101[0] = 1;
	for(int i=1;i<=100000;++i){
		p101[i] = 31LL*p101[i-1] % mod1;
		p102[i] = 31LL*p102[i-1] % mod2;
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int n,m;
		scanf("%d %d", &n, &m);
		scanf("%s", s);
		build(0, n-1, 0);
		while(m--){
			int p;
			int a, b;
			char c;
			scanf("%d", &p);
			if(p == 1){
				scanf("%d %c", &a, &c);
				update(0, n-1, 0, a-1, c-'0'+1);
			}
			else{
				scanf("%d %d", &a, &b);
				pair<pii, pii> res = query(0, n-1, 0, a-1, b-1);
				// printf("%d %d %d %d\n", res.fi.fi, res.fi.se, res.se.fi, res.se.se);
				if(res.fi.fi == res.se.fi && res.fi.se == res.se.se){
					puts("Adnan Wins");
				}
				else{
					puts("ARCNCD!");
				}
			}
		}
	}
	return 0;
};