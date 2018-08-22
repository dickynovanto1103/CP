
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

template<class T>
struct mapper{
	std::vector<T> m;
	mapper(){}
	void mapping(){
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	int get(T val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
	int upp(T val){ return upper_bound(m.begin(), m.end(), val) - m.begin();}
	int operator[] (T val){ return get(val);}
};

int n,i,j,k,t;
int a,b,c,d,q;
int x[200002], y[200002];
pair<pii, int> w[200002];
vector<pii> v;
mapper<int> mep;
int tree[800002], ans[200002];

void update(int l, int r, int pos, int idx, int d){
	if(r < idx || l > idx)
		return;
	if(l == r){
		tree[pos]+= d;
		return;
	}
	int mid = (l+r)>>1;
	update(l, mid, 2*pos+1, idx, d);
	update(mid+1, r, 2*pos+2, idx, d);
	tree[pos] += d;
}

int query(int l, int r, int pos, int ql, int qr){
	if(r < ql || l > qr)
		return 0;
	if(l>=ql && r<=qr)
		return tree[pos];
	int mid = (l+r)>>1;
	return query(l, mid, 2*pos+1, ql, qr) + query(mid+1, r, 2*pos+2, ql, qr);
}

int main(){
	for(int cc=1;scanf("%d", &n), n>0;++cc){
		printf("Case %d:\n", cc);
		for(i=0;i<n;++i)
			scanf("%d %d", x+i, y+i);
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &q);
		for(i=0;i<n;++i){
			v.pb({(x[i]-a)*(x[i]-a)+(y[i]-b)*(y[i]-b),(x[i]-c)*(x[i]-c)+(y[i]-d)*(y[i]-d)});
			mep.m.pb((x[i]-c)*(x[i]-c)+(y[i]-d)*(y[i]-d));
		}
		mep.mapping();
		for(i=0;i<n;++i)
			v[i].se = mep.get(v[i].se);
		sort(v.begin(), v.end());
		for(i=0;i<q;++i){
			scanf("%d %d", &w[i].fi.fi, &w[i].fi.se);
			w[i].fi.fi *= w[i].fi.fi;
			w[i].fi.se *= w[i].fi.se;
			w[i].fi.se = mep.upp(w[i].fi.se);
			w[i].se = i;
		}
		sort(w, w+q, [](const pair<pii, int> a, const pair<pii, int> b){
			return a.fi.fi > b.fi.fi;
		});
		// for(int x : mep.m)
		// 	cout<<x<<" ";
		// cout<<endl;
		// for(i=0;i<n;++i)
		// 	cout<<"v : "<<v[i].fi<<" "<<v[i].se<<endl;
		memset(tree, 0, 16*n);
		for(i=0, j=n;i<q;++i){
			// cout<<"w : "<<w[i].fi.fi<<" "<<w[i].fi.se<<" "<<w[i].se<<endl;
			while(j>0 && v[j-1].fi > w[i].fi.fi){
				j--;
				update(0, n-1, 0, v[j].se, 1);
			}
			// cout<<j<<" "<<w[i].fi.se<<" "<<n<<endl;
			if(j>=n || w[i].fi.se>=mep.m.size())
				ans[w[i].se] = 0;
			else
				ans[w[i].se] = query(0, n-1, 0, w[i].fi.se, n-1);
		}
		memset(tree, 0, 16*n);
		for(i=q-1,j=-1;i>=0;--i){
			while(j<n && v[j+1].fi <= w[i].fi.fi){
				j++;
				update(0, n-1, 0, v[j].se, 1);
			}
			if(j<0 || w[i].fi.se ==0)
				continue;
			else
				ans[w[i].se] -= query(0, n-1, 0, 0, w[i].fi.se-1);
		}
		for(i=0;i<q;++i)
			printf("%d\n", max(ans[i], 0));
		mep.m.clear();
		v.clear();
	}
	return 0;
}