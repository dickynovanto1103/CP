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
	int solve(int l, int r) {
		if(pas[l] == r) {
			if(r == l + 1) {
				return 1;
			}

			return 2 * solve(l+1, r-1);
		}

		int sum = 0;
		int idx = l;
		while(idx < r) {
			sum += solve(idx, pas[idx]);
			idx = pas[idx];
			idx++;
		}
		return sum;
	}

    int scoreOfParentheses(string s) {
		stack<int> st;
		for(int i=0;i<s.size();i++){
			char c = s[i];
			if(c == '(') {
				st.push(i);
			}else{
				int pair = st.top(); st.pop();
				pas[pair] = i;
				pas[i] = pair;
			}
		}

		this->s = s;

		return solve(0, s.size() - 1);
    }
private:
	string s;
	int pas[51];
};

int main(){
	string s;
	while(cin>>s) {
		Solution sol;
		cout<<sol.scoreOfParentheses(s)<<endl;
	}
	
	return 0;
};