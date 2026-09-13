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

class UFDS {
public:
	vector<int> size, parent;
	UFDS(int n) {
		size.resize(n, 1);
		for(int i=0;i<n;i++){
			parent.pb(i);
		}
	}

	int find(int node) {
		if(parent[node] == node) {
			return node;
		}

		return parent[node] = find(parent[node]);
	}

	void join(int a, int b) {
		int resA = find(a);
		int resB = find(b);
		if(resA == resB) {return;}

		if(size[resA] > size[resB]) {
			parent[resB] = resA;
			size[resA] += size[resB];
		}else{
			parent[resA] = resB;
			size[resB] += size[resA];
		}
	}

	int sz(int a) {
		return size[find(a)];
	}
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	int idx = 0;
    	unordered_map<int, int> mapper;
  		for(int i=0;i<nums.size();i++){
  			if(mapper.find(nums[i]) == mapper.end()) {
  				mapper[nums[i]] = idx++;
  			}
  		}
  		// puts("after mapping");

  		UFDS ufds((int)mapper.size());
  		// puts("after ufds");

  		int ans = 0;

  		for(int i=0;i<nums.size();i++){
  			int num = nums[i];
  			int idxBefore = mapper.find(num - 1) == mapper.end() ? -1 : mapper[num - 1];
  			int idxAfter = mapper.find(num + 1) == mapper.end() ? -1: mapper[num + 1];
  			// printf("num: %d idx: %d idxBefore: %d idxAfter: %d\n", num, mapper[num], idxBefore, idxAfter);

  			if(idxBefore != -1) {
  				ufds.join(mapper[num], idxBefore);
  			}

  			if(idxAfter != -1) {
  				ufds.join(mapper[num], idxAfter);
  			}

  			ans = max(ans, ufds.sz(mapper[num]));
  		}

  		return ans;
    }
};

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {
		vi v;
		for(int i=0;i<n;i++){
			int num;
			scanf("%d",&num);
			v.pb(num);
		}

		Solution sol;
		printf("%d\n", sol.longestConsecutive(v));
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