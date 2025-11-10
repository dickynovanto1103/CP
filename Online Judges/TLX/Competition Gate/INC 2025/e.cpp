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

struct Node {
	int f[16];
};

class SegmentTree {
	private:
		vector<tuple<char, int>> v;
		vector<Node> st;
		int n;

		int left(int n) {return (n << 1);}
		int right(int n) {return (n << 1) + 1;}

		void processAtIdx(int node, int idx) {
			char op = get<0>(v[idx]);
			int num = get<1>(v[idx]);
			for(int i=0;i<16;i++){
				if(op == '+') {
					st[node].f[i] = (i + num) % 16;
				}else {
					st[node].f[i] = (i ^ num);
				}
			}
			
		}

		void combine(int node){
			for(int i=0;i<16;i++){
				int output = st[left(node)].f[i];
				int final = st[right(node)].f[output];
				st[node].f[i] = final;
			}
		}

		void build(int node, int l, int r) {
			if(l == r) {
				processAtIdx(node, l);
				return;
			}

			int mid = (l + r) / 2;
			build(left(node), l, mid);
			build(right(node), mid + 1, r);
			combine(node);
		}

		void update(int node, int l, int r, int idx, tuple<char, int> tup) {
			if(r < idx || l > idx) {
				return;
			}

			if(l == r && l == idx) {
				v[idx] = tup;
				processAtIdx(node, idx);
				return;
			}

			int mid = (l + r) / 2;
			update(left(node), l, mid, idx, tup);
			update(right(node), mid + 1, r, idx, tup);
			combine(node);
		}
	public:
		SegmentTree(const vector<tuple<char, int>> _v, int n) {
			v = _v;
			this->n = n;
			st.assign(4 * n, Node());
			build(1, 1, n);
		}

		void update(int idx, tuple<char, int> tup) {
			return update(1, 1, n, idx, tup);
		}

		int query() {
			return st[1].f[0];
		}
};

void solve(){
	int n,m;
	while(scanf("%d %d\n",&n,&m) != EOF) {
		char c;
		int num;

		vector<tuple<char, int>> v;
		v.emplace_back('a', 0);
		for(int i=0;i<n;i++){
			scanf("%c %d\n", &c, &num);
			// printf("%c %d\n", c, num);
			v.emplace_back(c, num);
		}

		SegmentTree st(v, n);
		while(m--){
			int idxModule, num;
			char op;
			// cin>>idxModule>>op>>num;
			scanf("%d %c %d", &idxModule, &op, &num);
			// printf("%d %c %d\n", idxModule, op, num);
			st.update(idxModule, make_tuple(op, num));
			printf("%d\n", st.query());
		}
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};