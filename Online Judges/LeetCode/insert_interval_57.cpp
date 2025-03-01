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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        ii newPair = ii(newInterval[0], newInterval[1]);

        for(int i=0;i<intervals.size();i++){
        	ii cur = ii(intervals[i][0],intervals[i][1]);
        	if(isIntersect(cur, newPair)) {
        		newPair = merge(cur, newPair);
        	}else if(newPair != ii(-1, -1) && newPair.first < cur.first) {
        		res.push_back({newPair.first, newPair.second});
        		res.push_back({cur.first, cur.second});
        		newPair = ii(-1,-1);
        	}else if(newPair != ii(-1,-1) && cur.first < newPair.first) {
				res.push_back({cur.first, cur.second});
        		res.push_back({newPair.first, newPair.second});
        		newPair = ii(-1,-1);
        	}else{
        		res.push_back(intervals[i]);
        	}
        }

        if(newPair != ii(-1,-1)) {
        	res.push_back({newPair.first, newPair.second});
        }

        return res;
    }

    bool isIntersect(ii a, ii b) {
        return max(a.first, b.first) <= min(a.second, b.second);
    }

    ii merge(ii a, ii b) {
        return ii(min(a.first, b.first), max(a.second, b.second));
    }


};

void solve(){

}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};