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
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

vi merge(vi a, vi b, int n) {
	priority_queue<iii, viii, greater<iii>> pq;
	for(int i=0;i<n;i++){
		pq.push(iii(a[i] + b[0], ii(i, 0)));
	}

	vi res;
	while(res.size() < n) {
		iii top = pq.top(); pq.pop();
		res.pb(top.first);
		ii idx = top.second;
		if(idx.second == n-1) {
			continue;
		}

		int sum = top.first - b[idx.second] + b[idx.second + 1];
		pq.push(iii(sum, ii(idx.first, idx.second + 1)));
	}

	return res;
}

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {
		vector<vector<int>> mat;
		mat.assign(n, vector<int>(n, 0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
			}
			sort(mat[i].begin(), mat[i].end());
		}

		vi cur = mat[0];
		for(int i=1;i<n;i++){
			cur = merge(cur, mat[i], n);
		}

		for(int i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d", cur[i]);
		}
		puts("");
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