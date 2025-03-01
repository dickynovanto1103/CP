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
    vector<string> arr;

    vector<string> shortestSubstrings(vector<string>& arr) {
        this->arr = arr;
        vector<string> ans(arr.size(), "-");
        for(int i=0;i<arr.size();i++){
            string s = arr[i];
            //get all substring of s, then search in other indexes in arr
            int sz = s.size();
            for(int j=0;j<sz;j++){
                for(int k=j;k<sz;k++){
                    string sub = s.substr(j, k-j+1);
                    if(ans[i] == "-"){
                        if(!isExistInOtherArr(sub, i)){
                            ans[i] = sub;
                        }
                    }else{
                        if(sub.size() > ans[i].size()) {
                            continue;
                        }else if(sub.size() == ans[i].size() && sub < ans[i] && !isExistInOtherArr(sub, i)){
                            ans[i] = sub;
                        }else if(sub.size() < ans[i].size() && !isExistInOtherArr(sub, i)) {
                            ans[i] = sub;
                        }
                    }
                }
            }

            if(ans[i] == "-") {
                ans[i] = "";
            }
        }

        return ans;
    }

    bool isExistInOtherArr(string sub, int idx) {
        for(int i=0;i<arr.size();i++){
            if(i == idx){continue;}
            if(arr[i].find(sub) != -1) {
                return true;
            }
        }

        return false;
    }
};

void solve(){

}

int main(){
    // int tc = 1;
    // scanf("%d",&tc);
    // while(tc--){
    //     solve();
    // }

    int n;
    while(cin>>n) {
        vector<string> v(n, "");
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        Solution s;
        vector<string> ans = s.shortestSubstrings(v);
        for(string st: ans) {
            if(st==""){cout<<"(empty)";}
            cout<<st<<" ";
        }
        cout<<endl;
    }

    return 0;
};