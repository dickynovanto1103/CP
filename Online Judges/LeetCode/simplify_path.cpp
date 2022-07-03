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
	vector<string> getVectorOfStringSeparatedBySlash(string path) {
		vector<string> v;
		int n = path.size();
		string s = "";
		for(int i=0;i<n;i++){
			if(path[i] == '/') {
				v.pb(s);
				s = "";
				continue;
			}
			s += path[i];
		}
		v.pb(s);
		return v;
	}

    string simplifyPath(string path) {
        string ans;
        vector<string> v = getVectorOfStringSeparatedBySlash(path);
        vector<string> realV;
        for(int i=0;i<v.size();i++){
        	string s = v[i];
        	if(s == "") {continue;}
        	else if(s == "."){continue;}
        	else if(s == ".."){
        		if(realV.size() == 0) {continue;}
        		realV.pop_back();
        		continue;
        	}
        	realV.pb(s);
        }
        for(int i=0;i<realV.size();i++){
        	ans += "/";
        	ans += realV[i];
        }
        if(ans == ""){ans = "/";}
        return ans;
    }
};

int main(){
	string s;
	while(cin>>s){
		Solution sol;
		cout<<sol.simplifyPath(s)<<endl;
	}	
	
	return 0;
};