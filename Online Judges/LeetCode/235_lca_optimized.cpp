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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(!root) {
    		// printf("returning null\n");
    		return NULL;
    	}

    	if(root->val == p->val || root->val == q->val) {
    		return root;
    	}

    	TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
    	TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);
    	// printf("root: %d\n", root->val);
    	// if(leftRes) {
    	// 	printf("left: %d\n", leftRes->val);
    	// }
    	// if(rightRes) {
    	// 	printf("right: %d\n", rightRes->val);
    	// }

    	if(leftRes && rightRes) {
    		// printf("returning root->val: %d\n", root->val);
    		return root;
    	}

    	return leftRes ? leftRes : rightRes;
    }
};


void solve(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->left->right = new TreeNode(6);
	puts("test");

	Solution sol;
	TreeNode* ans = sol.lowestCommonAncestor(root, new TreeNode(5), new TreeNode(6));
	printf("ans: %d\n", ans->val);
	ans = sol.lowestCommonAncestor(root, new TreeNode(5), new TreeNode(4));
	printf("ans: %d\n", ans->val);
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};