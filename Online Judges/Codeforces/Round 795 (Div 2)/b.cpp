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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int bil;
		int a[100010];
		map<int, int> idx, cnt;
		int index = 0;
		vector<vi> adj;
		adj.assign(n, vi());
		for(int i=0;i<n;i++){
			scanf("%d",&bil);
			a[i] = bil;
			if(idx.find(bil) == idx.end()) {
				idx[bil] = index++;
			}

			adj[idx[bil]].pb(i);
			cnt[bil]++;
		}

		bool valid = true;
		for(int i=0;i<n;i++){
			if(cnt[a[i]] == 1){valid =false; break;}
		}

		if(!valid){puts("-1"); continue;}

		vi ans;
		for(int i=0;i<index;i++){
			int sz = adj[i].size();
			assert(sz > 1);
			for(int j=1;j<sz;j++){
				ans.pb(adj[i][j]);
			}
			ans.pb(adj[i][0]);
		}

		assert(ans.size() == n);
		for(int bil: ans){
			printf("%d ", bil + 1);
		}
		puts("");
	}
	
	return 0;
};