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

const int mod = 1e9 + 7;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vi, greater<int> > pq;
        for(int num: nums) {
        	pq.push(num);
        }

        while(k--){
        	int top = pq.top(); pq.pop();
        	pq.push(top+1);
        }

        ll ans = 1;
        while(!pq.empty()) {
        	ans *= pq.top(); pq.pop();
        	ans %= mod;
        }

        return ans;
    }
};

int main(){
	int n,k;
	while(cin>>n>>k){
		vi a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		Solution sol;
		cout<<sol.maximumProduct(a, k)<<endl;
	}
	
	return 0;
};