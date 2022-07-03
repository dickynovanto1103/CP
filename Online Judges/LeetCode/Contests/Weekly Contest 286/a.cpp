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

class Solution {
public:
	vector<int> findDiff(vector<int>& nums1, vector<int>& nums2) {
		set<int> s;
        set<int>::iterator it;
        for(int i=0;i<nums1.size();i++){
        	bool found = false;
        	for(int j=0;j<nums2.size();j++){
        		if(nums1[i] == nums2[j]) {
        			found = true;
        			break;
        		}
        	}
        	if(!found) {
        		s.insert(nums1[i]);
        	}
        }

        vi ans;
        for(it=s.begin();it!=s.end();it++){
        	ans.pb(*it);
        }

        return ans;
	}

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vi> ans;

        // vi satu = findDiff(nums1, nums2);
        ans.pb(findDiff(nums1, nums2));
        ans.pb(findDiff(nums2, nums1));
        return ans;
    }
};

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n, &m) != EOF) {
		vi a(n), b(m);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		for(int i=0;i<m;i++){
			scanf("%d",&b[i]);
		}

		Solution sol;
		vector<vi> answers = sol.findDifference(a, b);
		// printf("halo\n");
		for(vi ans: answers) {
			for(int bil: ans) {
				printf("%d ", bil);
			}
			puts("");
		}
	}
	
	return 0;
};