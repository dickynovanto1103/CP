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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int tree[400012];
int ma[100003];
vector<pii> v[100002];
pair<pii, int> p[100002];

void build(){
	memset(tree, 0, sizeof tree);
}

void update(int l, int r, int pos, int idx, int val){
	if(l > idx || r < idx)
		return;
	if(l == r){
		tree[pos] = val;
		return;
	}
	int mid = (l + r)/2;
	update(l, mid, 2*pos+1, idx, val);
	update(mid+1, r, 2*pos+2, idx, val);
	tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

int query(int l, int r, int pos, int ql, int qr){
	if(l > qr || r < ql)
		return 0;
	if(l>=ql && r<=qr)
		return tree[pos];
	int mid = (l+r)/2;
	return max(query(l, mid, 2*pos+1, ql, qr), query(mid+1, r, 2*pos+2, ql, qr));
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n,m;
		memset(ma, 0, sizeof ma);
		scanf("%d %d", &n, &m);
		for(int i=0;i<n;++i){
			int a,b,c;
			scanf("%d %d %d", &p[i].fi.fi, &p[i].fi.se, &p[i].se);
		}
		for(int i=0;i<m;++i){
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			v[c].pb({a, b});
		}
		sort(p, p+n);
		set<pii> s;
		int ans = 0;
		for(int i=1, j=0;i<=100000;++i){
			while(j < n && p[j].fi.fi <= i){
				update(1, 100000, 0, p[j].se, p[j].fi.se - p[j].fi.fi + 1);
				s.insert({p[j].fi.se, j});
				++j;
			}
			while(!s.empty() && s.begin()->fi < i){
				update(1, 100000, 0, p[s.begin()->se].se, 0);
				s.erase(s.begin());
			}
			if(s.empty()) continue;
			for(const pii &x : v[i]){
				ans = max(ans, query(1, 100000, 0, x.fi, x.se) + x.se - x.fi + 1);
			}
		}
		printf("%d\n", ans);
		for(int i=1;i<=100000;++i){
			v[i].clear();
		}
	}
	return 0;
};