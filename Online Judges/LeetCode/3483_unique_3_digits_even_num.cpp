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
    int totalNumbers(vector<int>& digits) {
    	int cnt[10] = {0};
  		for(int num: digits) {
  			cnt[num]++;
  		}

  		int ans = 0;
  		for(int i=0;i<10;i+=2){
  			if(cnt[i] == 0) {continue;}
  			cnt[i]--;

  			for(int j=1;j<10;j++){
  				if(cnt[j] == 0) {continue;}
  				cnt[j]--;
  				for(int k=0;k<10;k++){
  					if(cnt[k] == 0) {continue;}
  					ans++;
  				}
  				cnt[j]++;
  			}
  			cnt[i]++;
  		}

  		return ans;
    }
};

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {
		vi v(n);
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}
		Solution sol;
		printf("%d\n", sol.totalNumbers(v));
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