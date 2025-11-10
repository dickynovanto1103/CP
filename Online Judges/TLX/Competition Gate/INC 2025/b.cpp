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

void solve(){
	int n,m;
	int tt = 1;
	while(scanf("%d%d",&n,&m) != EOF) {
		if(tt > 1) {puts("");}
		tt++;

		int a[n+1];
		bool isVisited[n+10] = {false};

		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		if(m < (n-1)) {
			puts("-1 -1");
			continue;
		}

		vii edges;
		for(int i=0;i<n-1;i++){
			edges.pb(ii(a[i],a[i+1]));
		}

		bool done = edges.size() == m;
		if(done) {
			for(ii edge: edges) {
				printf("%d %d\n", edge.first, edge.second);
			}
			continue;
		}

		for(int i=0;i<n-1;i++){
			int maxUnvisited = inf;
			if(!isVisited[a[i+1]]) {
				isVisited[a[i+1]] = true;
				maxUnvisited = a[i+1];
			}
			for(int j=i+2;j<n;j++){
				if(done) {
					break;
				}
				if(isVisited[a[j]]) {
					edges.pb(ii(a[i], a[j]));
					done = edges.size() == m;
					continue;
				}

				if(maxUnvisited == inf) {
					maxUnvisited = a[j];
					isVisited[a[j]] = true;
					edges.pb(ii(a[i], a[j]));
					done = edges.size() == m;
				}else if(maxUnvisited > a[j]) {
					break;
				}else{
					maxUnvisited = max(maxUnvisited, a[j]);
					edges.pb(ii(a[i], a[j]));
					isVisited[a[j]] = true;
					done = edges.size() == m;
				}

				if(done) {
					break;
				}
			}

			if(done) {
				break;
			}
		}

		// printf("done: %d edge size: %d\n", done, edges.size());

		if(!done) {
			puts("-1 -1");
			continue;
		}

		for(ii edge: edges) {
			printf("%d %d\n", edge.first, edge.second);
		}
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