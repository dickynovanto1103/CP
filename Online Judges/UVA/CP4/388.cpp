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
	int n;
	while(scanf("%d", &n) != EOF) {
		double values[256] = {0};
		unordered_map<char, vector<char>> adj;
		for(int i=0;i<n;i++){
			char c;
			double value;	
			string neighbors;
			cin>>c>>value>>neighbors;
			// cout<<c<<" "<<value<<" "<<neighbors<<endl;
			values[c] = value;
			for(int j=0;j<neighbors.size();j++){
				char v = neighbors[j];
				adj[c].pb(v);
				adj[v].pb(c);
			}
		}

		double maxRemaining = -1;
		char from = 'a';
		for(char start='A'; start <= 'Z';start++) {
			double remaining[256] = {0};
			bool isVisited[256] = {false};
			remaining[start] = values[start];
			isVisited[start] = true;
			queue<int> q;
			q.push(start);
			while(!q.empty()) {
				int node = q.front(); q.pop();
				for(int i=0;i<adj[node].size();i++){
					char v = adj[node][i];
					if(!isVisited[v]) {
						remaining[v] = remaining[node] * 0.95;
						q.push(v);
						isVisited[v] = true;
					}
				}
			}

			if(!isVisited['*']) {
				continue;
			}

			if(remaining['*'] > maxRemaining) {
				maxRemaining = remaining['*'];
				from = start;
			} 
		}
		
		assert(from != 'a');
		printf("Import from %c\n", from);
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