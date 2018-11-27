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
#define se second
#define fi first
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

struct people
{
	int b,f;
	ll d;
	people(){d=b=f=0;}
	people(int _b, int _f, ll _d){
		b = _b;
		f = _f;
		d = _d;
	}
};

struct mapperint{
	std::vector<int> m;
	mapperint(){}
	mapperint(const vector<int> &arr){mapping(arr);}
	void mapping(const vector<int> &arr){
		m.clear();
		for(const int &x : arr)
			m.pb(x);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	int get(int val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
	int operator[] (int val){ return get(val);}
};

struct mapperpii{
	std::vector<pii> m;
	mapperpii(){}
	mapperpii(const vector<pii> &arr){mapping(arr);}
	void mapping(const vector<pii> &arr){
		m.clear();
		for(const pii &x : arr)
			m.pb(x);
		sort(m.begin(), m.end(), [](const pii &a, const pii &b){
			if(a.fi == b.fi)
				return a.se > b.se;
			return a.fi < b.fi;
		});
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	int get(pii val){return lower_bound(m.begin(), m.end(), val, [](const pii &a, const pii &b){
			if(a.fi == b.fi)
				return a.se > b.se;
			return a.fi < b.fi;
		}) - m.begin();}
	int operator[] (pii val){ return get(val);}
};

int n,i,j,k,t;
int m;
people a[100002];
ll b[100002];
mapperint m2;
mapperpii mep;
ll ans[100002];
ll tree[400002];

void update(int l, int r, int pos, int d, ll val){
	if(l > d || r < d)
		return;
	if(l == r){
		tree[pos] = max(tree[pos], val);
		return;
	}
	int mid = (l+r)>>1;
	update(l, mid, 2*pos+1, d, val);
	update(mid+1, r, 2*pos+2, d, val);
	tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

ll query(int l, int r, int pos, int ql, int qr){
	if(l > qr || r < ql || ql > qr)
		return 0;
	if(l >= ql && r <= qr)
		return tree[pos];
	int mid = (l+r)>>1;
	return max(query(l, mid, 2*pos+1, ql, qr), query(mid+1, r, 2*pos+2, ql, qr));
}

int main(){
	memset(tree, 0, sizeof tree);
	memset(b, 0, sizeof b);
	scanf("%d", &n);
	std::vector<pii> w;
	std::vector<int> v;
	for(i=0;i<n;++i){
		scanf("%d %d %lld", &a[i].b, &a[i].f, &a[i].d);
		w.pb({a[i].b, a[i].f});
	}
	mep.mapping(w);
	for(i=0;i<n;++i){
		v.pb(a[i].f);
		b[mep[{a[i].b, a[i].f}]] += a[i].d;
	}
	for(pii x: mep.m)
		cout<<"("<<x.fi<<","<<x.se<<") ";
	cout<<endl;
	m2.mapping(v);
	m = mep.m.size();
	k = m2.m.size();
	for(i=0;i<m;++i){
		int idx = m2[mep.m[i].se];
		if(idx)
			ans[i] = query(0, k-1, 0, 0, idx-1) + b[i];
		else
			ans[i] = b[i];
		// cout<<i<<" "<<mep.m[i].fi<<" "<<mep.m[i].se<<" "<<idx<<" "<<query(0, k-1, 0, 0, idx-1)<<" "<<ans[i]<<endl;
		update(0, k-1, 0, idx, ans[i]);
	}
	printf("%lld\n", *max_element(ans, ans+m));
	return 0;
};