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
	bool isPalin(string s) {
		string rev = s;
		reverse(rev.begin(), rev.end());
		return rev == s;
	}

	string getString(string s, int a, int b) {
		string ans;
		for(int i=a;i<=b;i++){
			ans+=s[i];
		}
		return ans;
	}

    bool validPalindrome(string s) {
    	int n = s.size();
    	int i = 0, j = s.size() - 1;
    	while(i < j) {
    		if(s[i] != s[j]) {
    			return isPalin(getString(s, i+1, j)) || isPalin(getString(s, i, j-1));
    		}

    		i++;
    		j--;
    	}
    	
    	return true;
    }
};

int main(){
	string s;
	while(cin>>s) {
		Solution sol;
		cout<<sol.validPalindrome(s)<<endl;
	}	
	
	return 0;
};