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
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
    	sort(nums.begin(), nums.end());
    	sort(target.begin(), target.end());

        vector<vi> numsPar, targetPar;
        numsPar.assign(2, vi()); targetPar.assign(2, vi());
        for(int i=0;i<nums.size();i++){
        	numsPar[nums[i]%2].pb(nums[i]);
        }

        for(int i=0;i<target.size();i++){
        	targetPar[target[i]%2].pb(target[i]);
        }

        for(int i=0;i<2;i++){
        	assert(numsPar[i].size() == targetPar[i].size());
        }

        ll jumlahNaik = 0;
        for(int i=0;i<2;i++){
        	for(int j=0;j<targetPar[i].size();j++){
        		int bilTar = targetPar[i][j];
        		int bilNum = numsPar[i][j];
        		if(bilTar > bilNum) {
        			jumlahNaik += ((ll)bilTar - bilNum) / 2LL;
        		}
        	}
        }

        return jumlahNaik;
    }
};

int main(){
	
	
	return 0;
};