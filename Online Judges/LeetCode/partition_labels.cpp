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
	ii combine(ii a, ii b) {
		return ii(min(a.first, b.first), max(a.second, b.second));
	}
    vector<int> partitionLabels(string s) {
  		vi res;
  		fill(minIdx, minIdx+256, inf);
  		fill(maxIdx, maxIdx+256, -1);
  		for(int i=0;i<s.size();i++){
  			char c = s[i];
  			minIdx[c] = min(minIdx[c], i);
  			maxIdx[c] = max(maxIdx[c], i);
  		}

  		for(int i=0;i<s.size();i++){
  			char c = s[i];
  			int minim = minIdx[c];
  			int maks = maxIdx[c];
  			ii cur = ii(minim, maks);
  			for(int j=cur.first;j<=cur.second;j++){
  				char ch = s[j];
  				cur = combine(cur, ii(minIdx[ch], maxIdx[ch]));
  			}
  			res.pb(cur.second - cur.first + 1);
  			i = cur.second;
  		}
  		return res;
    }
private:
	int minIdx[256];
	int maxIdx[256];
};

int main(){
	Solution sol;
	string s;
	while(cin>>s) {
		vi ans = sol.partitionLabels(s);
		for(int num: ans) {
			printf("%d ", num);
		}
		puts("");
	}
	
	return 0;
};