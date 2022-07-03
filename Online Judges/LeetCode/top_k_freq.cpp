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

bool cmp(ii a, ii b) {
	return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vi ans;

        unordered_map<int, int> cnt, vis;
        for(int num: nums) {
        	cnt[num]++;
        }

        vii listPas;
        for(int num: nums) {
        	if(!vis[num]) {
        		listPas.pb(ii(num, cnt[num]));
        		vis[num] = 1;
        	}
        }

        sort(listPas.begin(), listPas.end(), cmp);
        assert(listPas.size() >= k);
        for(int i=0;i<k;i++){
        	ans.pb(listPas[i].first);
        }

        return ans;
    }
};

int main(){
	int n,k;
	while(scanf("%d %d",&n,&k) != EOF) {
		vi a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		Solution sol;
		vi nums = sol.topKFrequent(a, k);
		for(int num: nums) {
			printf("%d ", num);
		}
		puts("");
	}
	
	return 0;
};