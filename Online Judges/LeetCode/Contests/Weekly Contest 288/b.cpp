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
	ll calcNumStartEnd(string s, int begin, int end) {
		if(begin > end) {
			//untuk case invalid, biar bs dikali 0
			return 1;
		}
		ll ans = 0;
		for(int i=begin;i<=end;i++){
			int num = s[i] - '0';
			ans *= 10;
			ans += num;
		}

		return ans;
	}

	string str(string s, int begin, int end) {
		string res;
		for(int i=begin;i<=end;i++){
			res += s[i];
		}
		return res;
	}

    string minimizeResult(string expression) {
        string ans = "(" + expression + ")";

        int idxPlus = expression.find("+");
        ll minim = calcNumStartEnd(expression, 0, idxPlus-1) + calcNumStartEnd(expression, idxPlus+1, expression.size() - 1);
        int sz = expression.size();
        for(int i=0;i<=idxPlus-1;i++){
        	for(int j=idxPlus+1;j<sz;j++){
        		ll dalamKurung = (calcNumStartEnd(expression, i, idxPlus - 1) + calcNumStartEnd(expression, idxPlus+1, j));
        		// printf("dalamKurung satu: %lld, dari: %d sampe: %d\n", calcNumStartEnd(expression, i, idxPlus - 1), i, idxPlus - 1);
        		// printf("dalamKurung dua: %lld, dari: %d sampe: %d\n", calcNumStartEnd(expression, idxPlus+1, j), idxPlus + 1, j);
        		ll res = calcNumStartEnd(expression, 0, i-1) * dalamKurung * calcNumStartEnd(expression, j + 1, sz-1);
        		// printf("i: %d j: %d dalamKurung: %lld, res: %lld\n", i, j, dalamKurung, res);
        		if(minim > res){
        			minim = res;
        			ans = str(expression, 0, i-1) + "(" + str(expression, i, j) + ")" + str(expression, j+1, sz-1);
        		}
        	}
        }
        // printf("minim: %lld\n", minim);

        return ans;
    }
};

int main(){
	string s;
	while(cin>>s) {
		Solution sol;
		cout<<sol.minimizeResult(s)<<endl;
	}	
	
	return 0;
};