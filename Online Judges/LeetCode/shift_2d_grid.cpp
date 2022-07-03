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
	ii convertIntToPair(int bil, int n, int m) {
		int mod = n * m;
		bil %= mod;
		int row = bil / m;
		return ii(bil / m, bil % m);
	}
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    	vector<vi> res;

    	int n = grid.size();
    	int m = grid[0].size();
    	for(int i=0;i<n;i++){
    		vi row(m);
    		for(int j=0;j<m;j++){
    			row[j] = 0;
    		}
    		res.pb(row);
    	}

    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			int angka = grid[i][j];
    			int koorAngka = i * m + j;
    			ii koorBaru = convertIntToPair(koorAngka + k, n, m);
    			res[koorBaru.first][koorBaru.second] = angka;
    		}
    	}

        return res;
    }
};

int main(){
	int n,m,k;
	while(cin>>n>>m>>k) {
		vector<vi> grid;
		for(int i=0;i<n;i++){
			vi row(m);
			for(int j=0;j<m;j++){
				cin>>row[j];
			}

			grid.pb(row);
		}

		Solution sol;
		vector<vi> res = sol.shiftGrid(grid, k);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ", res[i][j]);
			}
			puts("");
		}
		puts("");
	}
	
	return 0;
};