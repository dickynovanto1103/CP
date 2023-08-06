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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6;

const ll mod = (1LL<<62) - 57; //prime num
const ll SEED = chrono::steady_clock::now().time_since_epoch().count();

ll getHash(int v) {
	unsigned long long x = v + SEED;
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return (x ^ (x >> 31)) % mod;
}

ll a[maxn + 2];
ll tree[4 * maxn + 2];
map<ll, bool> rainbow;

class SegTree {
public:
	SegTree(int n) {
		for(int i=0;i<=4*n;i++) {
			tree[i] = 0;
		}
	}

	int left(int node) {return 2*node;}
	int right(int node) {return 2*node + 1;}

	void update(int node, int l, int r, int idx, ll val) {
		if(idx < l || idx > r) return;
		if(idx == l && idx == r) {
			tree[node] = val;
			return;
		}

		int mid = (l + r) / 2;
		update(left(node), l, mid, idx, val);
		update(right(node), mid+1, r, idx, val);

		tree[node] = (tree[left(node)] + tree[right(node)]) % mod;
	}

	ll query(int node, int l, int r, int lq, int rq) {
		if(r < lq || l > rq) return 0;
		if(lq <= l && r <= rq) return tree[node];

		int mid = (l + r) / 2;
		ll ans1 = query(left(node), l, mid, lq, rq);
		ll ans2 = query(right(node), mid+1, r, lq, rq);

		return (ans1 + ans2) % mod;
	}
};

int main(){
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		cerr<<"processing case "<<tt<<endl;
		printf("Case #%d: ", tt);
		int n;
		scanf("%d",&n);
		
		rainbow.clear();

		SegTree st(n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			rainbow[getHash(a[i])] = true;
			st.update(1, 1, n, i, getHash(a[i]));
		}

		int q;
		scanf("%d",&q);

		int ans = 0;
		while(q--){
			int cmd, aa, bb;
			scanf("%d %d %d",&cmd, &aa, &bb);
			if(cmd == 1) {
				int idx = aa, val = bb;
				rainbow[getHash(val)] = true;
				st.update(1, 1, n, idx, getHash(val));
			}else{
				int l, r;
				l = aa, r = bb;
				if((r - l + 1) % 2 == 0) continue;
				if(l == r){
					ans++; continue;
				}

				int mid = (l + r) / 2;
				//coba 2 kemungkinan
				//(l, mid), (mid+1, r)
				{
					ll besar = st.query(1, 1, n, l, mid);
					ll kecil = st.query(1, 1, n, mid+1, r);

					ll sisa = (besar - kecil + mod) % mod;
					if(rainbow.count(sisa)) {
						ans++;
						continue;
					}
				}

				//(l, mid - 1), (mid, r)
				{
					ll kecil = st.query(1, 1, n, l, mid-1);
					ll besar = st.query(1, 1, n, mid, r);

					ll sisa = (besar - kecil + mod) % mod;
					if(rainbow.count(sisa)) {
						ans++;
						continue;
					}
				}
			}

		}

		printf("%d\n", ans);

	}
	
	return 0;
};