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
typedef pair<char,int> ci;
typedef pair<string, ci> sci;
typedef pair<string, char> sc;
typedef pair<int, sc> isc;

void solve(){
	int n;
	while(cin>>n, n) {
		string awal, akhir;
		cin>>awal>>akhir;

		unordered_map<string, vector<sci>> adj;

		for(int i=0;i<n;i++){
			string a,b,w;
			cin>>a>>b>>w;
			adj[a].pb(sci(b, ci(w[0], w.size())));
			adj[b].pb(sci(a, ci(w[0], w.size())));
		}

		map<sc, int> dist;
		dist[sc(awal, ' ')] = 0;
		priority_queue<isc, vector<isc>, greater<isc>> pq;
		pq.push(isc(0, sc(awal, ' ')));
		while(!pq.empty()) {
			isc top = pq.top(); pq.pop();
			int curDist = top.first;
			string node = top.second.first;
			char prevBeginChar = top.second.second;

			if(curDist > dist[top.second]) {
				continue;
			}

			for(int i=0;i<adj[node].size();i++){
				sci v = adj[node][i];
				string ne = v.first;
				char begin = v.second.first;
				int w = v.second.second;

				if(begin == prevBeginChar) {
					continue;
				}

				if(dist.find(sc(ne, begin)) == dist.end() || dist[sc(ne, begin)] > curDist + w) {
					int newDist = curDist + w;
					dist[sc(ne, begin)] = newDist;
					pq.push(isc(newDist, sc(ne, begin)));
				}
			}
		}

		int minimDist = inf;
		for(int i=0;i<26;i++){
			if(dist.find(sc(akhir, i + 'a')) != dist.end()) {
				minimDist = min(minimDist, dist[sc(akhir, i + 'a')]);
			}
		}
		
		if(minimDist == inf) {
			puts("impossivel");
		}else{
			printf("%d\n", minimDist);
		}
	}
}

int main(){
	FastSlowInput;
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};