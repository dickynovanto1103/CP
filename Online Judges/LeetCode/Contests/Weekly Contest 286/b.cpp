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
    int minDeletion(vector<int>& v) {
    	int ans = 0;
    	vi list;
    	if(v.size() == 0){
    		return 0;
    	}


  		for(int i=0;i<v.size() - 1;i++){
  			if(v[i] == v[i+1]) {
  				list.pb(i);
  			}
  		}

  		for(int i=0;i<list.size();i++){
  			if((list[i] - ans) % 2 == 0) {
  				ans++;
  			}
  		}

  		int remSize = v.size() - ans;
  		if(remSize % 2 == 0) {
  			return ans;
  		}else{
  			return ans + 1;
  		}
    }
};

int main(){
	int n,i,j;
	while(scanf("%d",&n) != EOF) {
		vi a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		Solution sol;
		cout<<sol.minDeletion(a)<<endl;
	}
	
	return 0;
};