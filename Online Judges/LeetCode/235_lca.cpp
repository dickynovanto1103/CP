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

class Solution {
public:
	vector<int> tempPath;
	vector<int> pathToP, pathToQ;
	bool found;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	tempPath.clear();
    	found = false;
        findPath(root, p);
        assert(found == true);
        pathToP = tempPath;


        tempPath.clear();
        found = false;
        findPath(root, q);
        pathToQ = tempPath;
        assert(found == true);

        // printPath(pathToP);
        // printPath(pathToQ);

        unordered_map<int, bool> mapper;
        for(int num: pathToQ) {
        	mapper[num] = true;
        }

        for(int i=pathToP.size() - 1;i>=0;i--){
        	if(mapper[pathToP[i]]) {
        		return new TreeNode(pathToP[i]);
        	}
        }

        return root;
    }

    void printPath(vi path) {
    	for(int num: path) {
    		printf("%d ", num);
    	}
    	puts("");
    }

    void findPath(TreeNode* root, TreeNode* toFind) {
    	if(found) {
    		return;
    	}

    	if(root == NULL) {return;}
    	if(root->val == toFind->val) {tempPath.pb(root->val); found = true; return;}
    	tempPath.pb(root->val);
    	if(root->left != NULL) {
    		findPath(root->left, toFind);	
    		if(found) {return;}
    		tempPath.pop_back();
    	}
    	
    	if(root->right != NULL) {
    		findPath(root->right, toFind);
    		if(found) {return;}
    		tempPath.pop_back();
    	}
    }
};


class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void solve(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->left->right = new TreeNode(6);

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