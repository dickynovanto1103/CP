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

bool cmp(int a, int b) {
	return a > b;
}

class Solution {
public:
    int largestInteger(int num) {
    	string s;
    	vi gen, gan;
        while(num) {
        	int mod = num % 10;
        	if(mod % 2 == 0) {
        		gen.pb(mod);
        	}else{
        		gan.pb(mod);
        	}
        	s += mod + '0';
        	num /= 10;
        }
        reverse(s.begin(), s.end());

        sort(gen.begin(), gen.end(), cmp);
        sort(gan.begin(), gan.end(), cmp);
        int idxGen = 0, idxGan = 0;

        // cout<<"s: "<<s<<endl;
        int ans = 0;
        for(int i=0;i<s.size();i++){
        	int num = s[i] - '0';
        	ans *= 10;
        	if(num % 2 == 0) {
        		ans += gen[idxGen++];
        	}else{
        		ans += gan[idxGan++];
        	}
        }


        return ans;
    }
};

int main(){
	int n;
	while(cin>>n) {
		Solution sol;
		cout<<sol.largestInteger(n)<<endl;
	}
	
	return 0;
};