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
typedef pair<ii,ii> iiii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;

class Solution {
public:
	int prev[200001];
	int next[200001];
	bool isValid[200011];
    int minOrAfterOperations(vector<int>& nums, int k) {
    	priority_queue<iii> pq;

    	int n = nums.size();
    	resetPrevNext(n);

    	for(int i=0;i<n-1;i++){
    		pq.push(iii(getPengurangan(nums[i], nums[i+1]), ii(i, i+1)));
    	}

    	for(int i=0;i<nums.size();i++){
    		string bin = getBinaryString(nums[i]);
    		cout<<bin<<endl;
    	}

    	printf("initial k: %d\n", k);

    	while(k--){
    		printf("k sekarang: %d\n", k);
    		assert(!pq.empty());
    		iii top = pq.top(); pq.pop();
    		printf("top: %d %d %d\n", top.first, top.second.first, top.second.second);
    		int a = top.second.first, b = top.second.second;
    		if(!(isValid[a] && isValid[b])) {
    			k++;
    			continue;
    		}


    		int newBil = nums[a] & nums[b];
    		//put new number in vector
    		nums.pb(newBil);
    		int idxBaru = nums.size() - 1;
    		printf("newBil: %d is inserted at idxBaru: %d\n", newBil, idxBaru);
    		//change prev and next of a

    		if(prev[a] != -1) {
    			next[prev[a]] = idxBaru;
    			printf("next[%d]: %d\n", prev[a], idxBaru);
    			pq.push(iii(getPengurangan(nums[prev[a]], nums[idxBaru]), ii(prev[a], idxBaru)));
    		}

    		if(next[b] != -1) {
    			prev[next[b]] = idxBaru;
    			printf("prev[%d]: %d\n", next[b], idxBaru);
    			pq.push(iii(getPengurangan(nums[next[b]], nums[idxBaru]), ii(idxBaru, next[b])));	
    		}
    		
    		
    		prev[idxBaru] = prev[a];
    		next[idxBaru] = next[b];

    		isValid[a] = isValid[b] = false;
    		printf("idx %d and %d is invalid\n\n", a, b);
    	}
    	
    	int ans = 0;
    	for(int i=0;i<nums.size();i++){
    		if(!isValid[i]) {
    			continue;
    		}
    		ans |= nums[i];
    		printf("final ans calculation: ");
    		string bin = getBinaryString(nums[i]);
    		cout<<bin<<endl;
    	}
        return ans;
    }

    int getPengurangan(int a, int b) {
    	return a + b - (a & b) * 2;
    }

    void resetPrevNext(int n){
    	memset(isValid, true, sizeof isValid);
    	memset(prev, -1, sizeof prev);
    	memset(next, -1, sizeof prev);

    	for(int i=0;i<n;i++){
    		
    		prev[i] = i-1;
    		next[i] = i+1;
    	}
    	next[n-1] = -1;
    }

    string getBinaryString(int num){
    	string s;
    	for(int i=31;i>=0;i--){
    		if((1<<i) & num) {
    			s += '1';
    		}else{
    			s += '0';
    		}
    	}
    	return s;
    }
};

int main(){
	// int tc = 1;
	// // scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	int n, k;
	while(cin>>n>>k){
		vi v;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			v.pb(a);
		}

		Solution s;
		int ans = s.minOrAfterOperations(v, k);
		printf("%d\n\n\n", ans);
	}
	return 0;
};