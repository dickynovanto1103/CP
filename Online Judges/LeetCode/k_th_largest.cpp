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

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        for(int i=(int)nums.size()-1;i>=0;i--){
        	pq.push(nums[i]);
        	if(pq.size() == k) {
        		break;
        	}
        }

        this->k = k;
    }
    
    int add(int val) {
    	if(pq.size() < k){
    		pq.push(val);
    		return pq.top();
    	}

        if(pq.top() < val) {
        	pq.pop();
        	pq.push(val);
        	return pq.top();
        }

        return pq.top();
    }

private:
	priority_queue<int, vi, greater<int> > pq;
	int k;
};


int main(){
	int n, k;
	while(scanf("%d %d",&n, &k) != EOF) {
		vi a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		KthLargest kth(k, a);
		int q;
		scanf("%d",&q);
		while(q--){
			int bil;
			scanf("%d",&bil);
			cout<<kth.add(bil)<<endl;
		}
	}
	
	
	return 0;
};