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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
};

class Solution {
public:
	int ans = 0;
    int averageOfSubtree(TreeNode* root) {
  		dfs(root);

  		return ans;
    }

    ii dfs(TreeNode* root) {
    	if(root == NULL) {return {0,0};}

    	auto [sumLeft, cntLeft] = dfs(root->left);
    	auto [sumRight, cntRight] = dfs(root->right);

    	int sumNow = root->val + sumLeft + sumRight;
    	int cntNow = 1 + cntLeft + cntRight;
    	if(sumNow / cntNow == root->val) {ans++;}
    	return {sumNow, cntNow};
    }
};

void solve(){
	TreeNode* root = new TreeNode()
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};