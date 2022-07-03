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
	bool can(vi targetList, int val) {
		for(int target: targetList) {
			if(val >= target) {
				return true;
			}
		}

		return false;
	}

	void printVector(vi v) {
		printf("vector: ");
		for(int a: v) {
			cout<<a<<" ";
		}
		puts("");
	}

    int brokenCalc(int startValue, int target) {
    	if(target <= startValue) {
    		return startValue - target;
    	}
    	// printf("startValue awal: %d target: %d\n", startValue, target);
  		vi div2OfTargetList;
  		int tempTarget = target;
  		div2OfTargetList.pb(tempTarget);
  		while(tempTarget % 2 == 0) {
  			tempTarget /= 2;
  			div2OfTargetList.pb(tempTarget);
  		}
  		printVector(div2OfTargetList);


  		int ans = 0;
  		while(!can(div2OfTargetList, startValue)) {
  			startValue *= 2;
  			ans++;
  		}
  		// printf("startValue: %d\n", startValue);
  		int valUnder = 0;
  		for(int tempTarget: div2OfTargetList) {
  			if(startValue >= tempTarget) {
  				valUnder = max(valUnder, tempTarget);
  			}
  		}

  		// printf("valUnder: %d\n", valUnder);

  		ans += startValue - valUnder;
  		startValue = valUnder;
  		while(startValue != target) {
  			startValue *= 2;
  			ans++;
  		}

  		return ans;

    }
};

int main(){
	int start, target;
	while(cin>>start>>target) {
		Solution sol;
		cout<<sol.brokenCalc(start, target)<<endl;
	}	
	
	return 0;
};