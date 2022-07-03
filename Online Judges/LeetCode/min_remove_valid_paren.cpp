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
    string minRemoveToMakeValid(string s) {
    	int n = s.size();
    	bitset<100000> isOk;
    	isOk.set();
        stack<int> st;

        for(int i=0;i<n;i++){
        	if(s[i] == '(') {
        		st.push(i);
        	}else if(s[i] == ')') {
        		if(st.empty()) {
        			isOk[i] = false;
        			continue;
        		}
        		st.pop();
        	}
        }

        while(!st.empty()) {
        	int idx = st.top(); st.pop();
        	isOk[idx] = false;
        }

        string res;
        for(int i=0;i<n;i++){
        	if(isOk[i]){
        		res += s[i];
        	}
        }
        return res;
    }
};

int main(){
	string s;
	while(cin>>s) {
		Solution sol;
		cout<<sol.minRemoveToMakeValid(s)<<endl;
	}
	
	return 0;
};