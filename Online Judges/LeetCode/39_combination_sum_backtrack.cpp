#include <bits/stdc++.h>

using namespace std;

void printVector(vector<vector<int>> v) {
	puts("[");
	for(int i=0;i<v.size();i++){
		printf("\t[");
		for(int j=0;j<v[i].size();j++){
			printf("%d, ", v[i][j]);
		}
		puts("]");
	}
	
	puts("]");
}

void printAloneVector(vector<int> v) {
	printf("[");
	for(int el: v) {
		printf("%d, ", el);
	}
	puts("]");
}

class Solution {
public:
	int n;
	vector<vector<int>> ans;
	vector<int> current;
	vector<int> candidates;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	n = candidates.size();
    	this->candidates = candidates;
    	solve(0, target);
    	return ans;
    }

   	void solve(int idx, int remaining) {
   		if(idx >= n) {
   			return;
   		}

    	if(remaining == 0) {
    		ans.push_back(current);
    		return;
    	}

    	if(remaining >= candidates[idx]) {
    		current.push_back(candidates[idx]);
    		solve(idx, remaining - candidates[idx]);
    		current.pop_back();
    	}

    	solve(idx+1, remaining);
    }
};

int main() {
	vector<int> v = {2,3,6,7};
	Solution sol;
	vector<vector<int>> ans = sol.combinationSum(v, 7);
	printVector(ans);

	v = {1,2,3};
	ans = sol.combinationSum(v, 3);
	printVector(ans);	

	v = {8,7,4,3};
	ans = sol.combinationSum(v, 11);
	printVector(ans);	
	return 0;
}