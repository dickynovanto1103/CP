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
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;

class LazyST {
public:
	vector<ll> lazy;
	vector<pll> tree;
	vector<ll> arr;

	LazyST(vll& arr) {
		this->arr = arr;
		int n = arr.size();
		tree.assign(4*n,{0,0});
		for(int i=0;i<4*n;i++){
			tree[i] = {0,i};
		}

		lazy.assign(4*n, 0);
		build(0,0,n-1);
	}

	int left(int node) {return node * 2 + 1;}
	int right(int node) {return node * 2 + 2;}

	void push(int node, int start, int end) {
		if(lazy[node] != 0) {
			tree[node].first += lazy[node];
			if(start != end) {
				lazy[left(node)] += lazy[node];
				lazy[right(node)] += lazy[node];
			}

			lazy[node] = 0;
		}
	}

	void build(int node, int start, int end) {
		if(start == end) {
			tree[node] = {arr[start], start};
			return;
		}

		int mid = (start + end) / 2;
		build(left(node), start, mid);
		build(right(node), mid + 1, end);
		tree[node] = max(tree[left(node)], tree[right(node)]);
		// printf("building, start: %d, end: %d, tree[left]: (%lld,%lld), tree[right]: (%lld,%lld), result: (%lld,%lld)\n", start, end, tree[left(node)].first, tree[left(node)].second, tree[right(node)].first, tree[right(node)].second, tree[node].first, tree[node].second);
	}

	void update(int node, int start, int end, int l, int r, ll val) {
		push(node, start, end);

		if(start > r || end < l || start > end) {
			return;
		}

		if(l <= start || end <= r) {
			tree[node].first += val;
			if(start != end) {
				lazy[left(node)] += val;
				lazy[right(node)] += val;
			}

			return;
		}

		int mid = (start + end) / 2;
		update(left(node), start, mid, l, r, val);
		update(right(node), mid + 1, end, l, r, val);

		tree[node] = max(tree[left(node)], tree[right(node)]);
		printf("start: %d, end: %d, tree[left]: (%lld,%lld), tree[right]: (%lld,%lld), result: (%lld,%lld)\n", start, end, tree[left(node)].first, tree[left(node)].second, tree[right(node)].first, tree[right(node)].second);
	}

	pll query(int node, int start, int end, int l, int r) {
		push(node, start, end);
		
		if(start > r || end < l || start > end) {
			return {(ll)-inf*inf, -1};
		}

		if(l <= start || end <= r) {
			// printf("under interval, start: %d, end: %d, res: (%lld,%lld)\n", start, end, tree[node].first, tree[node].second);
			return tree[node];
		}

		int mid = (start + end) / 2;
		pll ans1 = query(left(node), start, mid, l, r);
		pll ans2 = query(right(node), mid + 1, end, l, r);
		// printf("start: %d, end: %d, ans1: (%lld,%lld), ans2: (%lld,%lld)\n", start, end, ans1.first, ans1.second, ans2.first, ans2.second);
		return max(ans1, ans2);
	}
};

void solve(){
	int q,maxCap;
	while(scanf("%d%d",&q,&maxCap) != EOF) {
		vll arr(q, 0);
		LazyST st(arr);
		int n = q;

		int prevTime = 0;
		int idxAdd = 0;
		for(int i=0;i<q;i++){
			int type;
			scanf("%d",&type);
			printf("i: %d, type: %d, idxAdd: %d\n", i, type, idxAdd);
			if(type == 1) {
				int t,w;
				scanf("%d%d",&t,&w);
				if(prevTime > 0) {
					int selisih = t - prevTime;

					printf("selisih is added at range 0 to %d with selisih: %d\n", idxAdd-1, selisih);
					st.update(0,0,n-1,0,idxAdd-1, selisih);
					for(int j=0;j<=idxAdd;j++){
						pll val = st.query(0,0,n-1,j, j);
						printf("[DEBUG] at i: %d val: (%lld,%lld)\n", j, val.first, val.second);	
					}
				}
				printf("update at idxAdd: %d with w: %d\n", idxAdd, w);
				st.update(0,0,n-1,idxAdd,idxAdd,w);
				for(int j=0;j<=idxAdd;j++){
					pll val = st.query(0,0,n-1,j, j);
					printf("[DEBUG] at i: %d val: (%lld,%lld)\n", j, val.first, val.second);	
				}
				

				prevTime = t;
				idxAdd++;
			}else{
				int t;
				scanf("%d",&t);

				if(prevTime == 0) {
					puts("-1");
					continue;
				}

				int selisih = t - prevTime;
				printf("selisih is added at range 0 to %d with selisih: %d\n", idxAdd, selisih);
				st.update(0,0,n-1,0,idxAdd, selisih);
				for(int j=0;j<=idxAdd;j++){
					pll val = st.query(0,0,n-1,j, j);
					printf("[DEBUG] at i: %d val: (%lld,%lld)\n", j, val.first, val.second);	
				}
				pll maxResult = st.query(0,0,n-1,0,idxAdd);
				printf("maxResult: (%lld,%lld)\n", maxResult.first, maxResult.second);
				if(maxResult.first < 0) {
					puts("-1");
					continue;
				}else{
					printf("%lld\n", min(maxResult.first, (ll)maxCap));

					st.update(0,0,n-1,maxResult.second, maxResult.second, (ll)-inf*inf);
					for(int j=0;j<=idxAdd;j++){
						pll val = st.query(0,0,n-1,j, j);
						printf("[DEBUG] at i: %d val: (%lld,%lld)\n", j, val.first, val.second);	
					}
				}

				prevTime = t;
			}
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