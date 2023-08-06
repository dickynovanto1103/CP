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

const int OFFSET = 10001;

class SegmentTree {
public:
	SegmentTree(int n) {
		v.assign(n + 2, 0);
	}

	int left(int node) {return 2*node;}
	int right(int node) {return 2*node + 1;}

	int query(int node, int l, int r, int ll, int rr) {
		if( l > r) return 0;
		if(ll <= l && r <= rr) {
			// printf("sini\n");
			return v[node];
		}
		if(r < ll || l > rr) {
			// printf("pasti sini\n");
			return 0;
		}

		int mid = (l + r) / 2;
		return query(left(node), l, mid, ll, rr) + query(right(node), mid + 1, r, ll, rr);
	}

	void update(int node, int l, int r, int pos, int val) {
		if(l > r) return;
		if(pos < l || pos > r) return;
		// printf("halo");
		if(l == pos && pos == r) {v[node] += val; return;}

		int mid = (l + r ) / 2;
		update(left(node), l, mid, pos, val);
		update(right(node), mid + 1, r, pos, val);
		v[node] = v[left(node)] + v[right(node)];
	}

private:
	vi v;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        SegmentTree st(80000);

        int n = nums.size();
        vi ans;
        for(int i=n-1;i>=0;i--){
        	int val = nums[i];
        	st.update(1, 1, 10000 + OFFSET, val + OFFSET, 1);
        	ans.pb(st.query(1, 1, 10000 + OFFSET, 1, val - 1 + OFFSET));
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
	Solution sol;

	int n;
	while(cin>>n){
		vi v(n);
		for(int i=0;i<n;i++) scanf("%d",&v[i]);

		vi ans = sol.countSmaller(v);
		for(int val: ans) printf("%d ",val);
		puts("");
	}
	
	return 0;
};