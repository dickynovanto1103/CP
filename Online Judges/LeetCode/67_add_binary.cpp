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
    string addBinary(string a, string b) {
  		if(a.size() < b.size()) {swap(a,b);}

  		string ans;
  		//a size >= b.size
  		int idxA, idxB;
  		int carry = 0;

  		for(idxB=b.size() - 1, idxA = a.size() - 1;idxA>=0 && idxB >= 0;idxA--, idxB--){
  			// printf("idxB: %d idxA: %d\n", idxB, idxA);
  			int numInB = b[idxB] - '0';
  			int numInA = a[idxA] - '0';
  			int sum = numInB + numInA + carry;
  			
  			int mod = sum % 2;
  			ans += (mod + '0');
  			// printf("adding mod: %d\n", mod);
  			carry = (sum >= 2 ? 1 : 0);
  		}

  		for(int i=idxA;i>=0;i--){
  			int numInA = a[i] - '0';
  			int sum = numInA + carry;
  			
  			int mod = sum % 2;
  			ans += (mod + '0');
  			carry = (sum >= 2 ? 1 : 0);
  		}
  		if(carry == 1) {
  			ans += '1';
  		}

  		reverse(ans.begin(), ans.end());

  		return ans;
    }
};

void solve(){
	string a,b;
	while(cin>>a>>b) {
		Solution sol;

		string ans = sol.addBinary(a,b);
		cout<<ans<<endl;
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};