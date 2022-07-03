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

1 Fusionopolis Place, #17-10, Galaxis, Singapore 138522
1 FUSIONOPOLIS PLACE, #17-10, GALAXIS, SINGAPORE 138522

Bachelor of Science in Informatics/Computer Science
BACHELOR OF SCIENCE IN INFORMATICS/COMPUTER SCIENCE
Jl. Kentangan Bar. No.214, Jagalan, Kec. Semarang Tengah, Kota Semarang, Jawa Tengah 50613, Indonesia

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

bool cmp(int a, int b) {
    return a > b;
}
 
class Solution {
public:
    void collectAllValues(TreeNode* root) {
        if(root == NULL) return;
        listOfBil.pb(root->val);
        collectAllValues(root->left);
        collectAllValues(root->right);
    }

    TreeNode* addValuesIntoTree(TreeNode* root) {
        if(root == NULL) return root;
        
        root->val += sum[root->val];
        root->left = addValuesIntoTree(root->left);
        root->right = addValuesIntoTree(root->right);

        return root;
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        collectAllValues(root);
        sort(listOfBil.begin(), listOfBil.end(), cmp);

        sum[listOfBil[0]] = 0;
        int currSum = 0;
        for(int i=1;i<listOfBil.size();i++){
            int bil = listOfBil[i];
            currSum += listOfBil[i-1];
            sum[bil] = currSum;
        }

        return addValuesIntoTree(root);
    }

private:
    vi listOfBil;
    map<int,int> sum;
};

int main(){
    
    
    return 0;
};