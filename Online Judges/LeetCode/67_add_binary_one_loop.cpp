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

  		for(idxB=b.size() - 1, idxA = a.size() - 1;idxA>=0 || idxB >= 0 || carry;idxA--, idxB--){
  			// printf("idxB: %d idxA: %d\n", idxB, idxA);
  			int sum = (idxA >= 0 ? a[idxA] - '0': 0) + (idxB >= 0 ? b[idxB] - '0': 0) + carry;
  			
  			int mod = sum % 2;
  			ans += (mod + '0');
  			// printf("adding mod: %d\n", mod);
  			carry = sum / 2;
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