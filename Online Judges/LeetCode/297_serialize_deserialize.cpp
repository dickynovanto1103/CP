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

class Codec {
public:
	vector<int> v;
	vector<int> deserializedNums;
	int idx;

	string convertNumToStr(int num) {
		if(num == -inf){return "#";}
		bool isNegative = num < 0;
		string ans;
		if(isNegative) {num = -num;}
		while(num) {
			int digit = num % 10;
			ans += digit + '0';
			num /= 10;
		}
		reverse(ans.begin(), ans.end());

		return (isNegative ? "-": "") + ans;
	}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	v.clear();
    	deserializedNums.clear();
    	if(root == NULL) {return "";}
        traverse(root);

        string ans;
        for(int i=0;i<v.size();i++) {
        	ans += convertNumToStr(v[i]);
        	if(i == ((int)v.size() - 1)) {
        		continue;
        	}

        	ans += ',';
        }

        return ans;
    }

    void traverse(TreeNode* root) {
    	if(root == NULL) {v.pb(-inf); return;}
    	v.pb(root->val);
    	traverse(root->left);
    	traverse(root->right);
    }

    void convertStringToVector(string data) {
    	int num = 0;
    	bool isNegative = false;
    	for(int i=0;i<data.size();i++){
    		if(data[i] == '-'){
    			isNegative = true;
    		}else if(data[i] == ',') {
    			
    			deserializedNums.pb(num * (isNegative ? -1 : 1));
    			isNegative = false;
    			num = 0;
    		}else if(data[i] == '#') {
    			num = -inf;
    		}else{
    			num *= 10;
    			num += data[i] - '0';
    		}
    	}

    	deserializedNums.pb(num * (isNegative ? -1: 1));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if(data == "") {return NULL;}
    	convertStringToVector(data);
    	// printVector(deserializedNums);
    	if(deserializedNums.size() == 0) {
    		return NULL;
    	}

    	idx = 0;
        return formTree();
    }

    TreeNode* formTree() {
    	if(idx >= deserializedNums.size() || deserializedNums[idx] == -inf) {
    		idx++;
    		return NULL;
    	}

    	TreeNode* root = new TreeNode(deserializedNums[idx]);
    	idx++;
    	if(idx < deserializedNums.size()) {
    		root->left = formTree();
    		
    	}
    	// printf("after left, now idx: %d\n", idx);

    	if(idx < deserializedNums.size()) {
    		root->right = formTree();
    	}

    	return root;
    }

    void printVector(vi v) {
    	for(int el: v) {
    		printf("%d ", el);
    	}
    	puts("");
    }

    bool isSame(TreeNode* one, TreeNode* two) {
    	if(one == NULL) {
    		if(two != NULL) {return false;}
    		return true;
    	}
    	
    	if(two == NULL) {return false;}
    	return one->val == two->val && isSame(one->left, two->left) && isSame(one->right, two->right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

void solve(){
	Codec codec;
	TreeNode* root = new TreeNode(-1);
	root->left = new TreeNode(-2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(5);
	string serialRes = codec.serialize(root);
	cout<<serialRes<<endl;

	TreeNode* res = codec.deserialize(serialRes);
	printf("%d\n", codec.isSame(res, root));
	Codec newCodec;
	cout<<newCodec.serialize(res)<<endl;
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};