/*
YES
YES
NO
YES
NO
YES
NO
YES
YES
YES
NO
YES
*/
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

ll tree[800001];
ll lazy[800001];

class LazySegTree {
public:
	int left(int n) {
		return 2 * n;
	}

	int right(int n) {
		return 2 * n + 1;
	}

	void push(int node) {
		tree[left(node)] += lazy[node];
		tree[right(node)] += lazy[node];
		lazy[left(node)] += lazy[node];
		lazy[right(node)] += lazy[node];

		lazy[node] = 0;
	}

	ll query(int node, int l, int r, int ll, int rr) {
		if(l > r) {
			return -inf;
		}

		if(l > rr || r < ll) return -inf;

		if(ll <= l && r <= rr){
			return tree[node];
		}

		push(node);
		int mid = (l + r) / 2;

		return max(query(left(node), l, mid, ll, rr), query(right(node), mid+1, r, ll, rr));
	}

	void update(int node, int l, int r, int ll, int rr, int addend) {
		// printf("update: node: %d, l: %d r: %d\n", node, l, r);
		if(l > r) return;
		if(l > rr || r < ll) return;
		if(ll <= l && r <= rr) {
			tree[node] += addend;
			lazy[node] += addend;
			return;
		}

		push(node);
		int mid = (l + r)/2;
		update(left(node), l, mid, ll, rr, addend);
		update(right(node), mid+1, r, ll, rr, addend);
		tree[node] = max(tree[left(node)], tree[right(node)]);
	}

	void reset(int n) {
		for(int i=0;i<=4*n;i++){
			tree[i] = 0;
			lazy[i] = 0;
		}
	}
};

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		LazySegTree seg;
		seg.reset(n);
		
		int a[200001];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		bool valid = true;

		int left = -1, right = -1;
		for(int i=0;i<n;i++){
			// printf("i: %d\n", i);
			if(left != -1) {
				// printf("left: %d right: %d n: %d\n", left, right, n);
				printf("update dengan a[%d]: %d\n", i, a[i]);
				seg.update(1, 1, n, left, right, a[i]);
				ll nilai = seg.query(1, 1, n, left, right);
				printf("nilai di left: %d right: %d adalah: %lld\n", left, right, nilai);
				if(nilai > 0) {valid = false; break;}
			}

			if(a[i] > 0) {
				if(left == -1) {
					left = right = 1;
					continue;
				}

				right++;
			}
		}

		if(!valid) {
			puts("NO");
		}else{
			puts("YES");
		}
	}
	
	return 0;
};