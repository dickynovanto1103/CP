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
    int maxOperations(vector<int>& nums, int k) {
     	for(int i=0;i<nums.size();i++){
     		cnt[nums[i]]++;
     	}

     	int ans = 0;
     	for(int i=0;i<nums.size();i++){
     		int bil = nums[i];
     		int pasangan = k - bil;
     		if(vis[bil]) continue;

     		if(bil == pasangan) {
     			ans += cnt[bil] / 2;
     		}else {
     			ans += min(cnt[bil], cnt[pasangan]);	
     		}
     		
     		vis[bil] = true;
     		vis[pasangan] = true;
     	}

     	return ans;
    }

private:
	unordered_map<int,int> cnt;
	unordered_map<int, bool> vis;
};

int main(){
	int n,k;
	while(cin>>n>>k) {
		vi v(n);
		for(int i=0;i<n;i++) {
			cin>>v[i];
		}

		Solution sol;
		cout<<sol.maxOperations(v, k)<<endl;
	}
	
	return 0;
};