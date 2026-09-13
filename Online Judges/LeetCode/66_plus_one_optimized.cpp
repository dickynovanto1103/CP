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
    vector<int> plusOne(vector<int>& digits) {
  		for(int i=digits.size()-1;i>=0;i--){
  			if(++digits[i] < 10) {return digits;}
  			digits[i] = 0;
  		}

  		digits.insert(digits.begin(), 1);
  		return digits;
    }
};

void printVector(vi v) {
	for(int num: v) {
		printf("%d ", num);
	}
	puts("");
	puts("");
}

void solve(){
	Solution sol;
	vi v = {1, 2, 3};

	vi ans = sol.plusOne(v);
	printVector(ans);
	
	v = {9};
	ans = sol.plusOne(v);
	printVector(ans);
	
	v = {9, 9};
	ans = sol.plusOne(v);
	printVector(ans);

	v = {8};
	ans = sol.plusOne(v);
	printVector(ans);

	v = {1,2,9,9};
	ans = sol.plusOne(v);
	printVector(ans);
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};