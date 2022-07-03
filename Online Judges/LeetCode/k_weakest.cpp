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
	static bool cmp(ii a, ii b) {
		if(a.first == b.first) {
			return a.second < b.second;
		}
		return a.first < b.first;
	}
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
  		vi ans;

  		vii temp(mat.size());
  		for(int i=0;i<mat.size();i++){
  			vi row = mat[i];
  			int cnt = 0;
  			for(int j=0;j<row.size();j++){
  				if(row[j] == 1){
  					cnt++;
  				}	
  			}
  			temp[i] = ii(cnt, i);
  		}

  		sort(temp.begin(), temp.end(), cmp);
  		// for(ii pas: temp) {
  		// 	printf("cnt: %d idx: %d\n", pas.first, pas.second);
  		// }
  		for(int i=0;i<k;i++){
  			ans.pb(temp[i].second);
  		}

  		return ans;      
    }
};

int main(){
	int n,m,k;
	while(scanf("%d %d %d",&n,&m, &k) != EOF) {
		vector<vi> a(n, vi(m));

		for(int i=0;i<n;i++){

			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
				// printf("%d ", a[i][j]);
				// printf("n: %d m: %d i: %d j: %d\n", n,m, i,j);
			}
			// puts("");
		}

		Solution sol;
		vi ans = sol.kWeakestRows(a, k);
		for(int bil: ans) {
			printf("%d ", bil);
		}
		puts("");

		// cout<<sol??>?.kWeakestRows(a, k)<<endl;
	}
	
	return 0;
};