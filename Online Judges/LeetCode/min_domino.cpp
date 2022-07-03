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
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    	int n = tops.size();
    	int minCnt = inf;
    	int i,j;
        for(int num = 1; num <= 6; num++) {
        	//cek top;
        	int cnt = 0;
        	for(i=0;i<n;i++){
        		if(tops[i] == num) {
        			continue;
        		}
        		if(bottoms[i] == num) {
        			//swap
        			cnt++;
        		}else{
        			cnt = inf;
        			break;
        		}
        	}

        	minCnt = min(minCnt, cnt);
        	//cek bottom;
        	cnt = 0;
        	for(i=0;i<n;i++) {
        		if(bottoms[i] == num){continue;}
        		if(tops[i] == num) {
        			cnt++;
        		}else{
        			cnt = inf;
        			break;
        		}
        	}

        	minCnt = min(minCnt, cnt);
        }

        if(minCnt == inf){return -1;}
        return minCnt;
    }
};

int main(){
	Solution sol;
	int n;
	while(scanf("%d",&n) != EOF) {
		vi tops(n), bottoms(n);
		for(int i=0;i<n;i++){
			scanf("%d",&tops[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&bottoms[i]);
		}

		cout<<sol.minDominoRotations(tops, bottoms)<<endl;
	}
	
	return 0;
};