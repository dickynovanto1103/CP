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
typedef pair<int, int> ii;
typedef pair<double,ii> dii;
typedef vector<ii> vii;
typedef vector<dii> vdii;

const int maxn = 60;

struct UFDS {
	UFDS(int n) {
		for(int i=0;i<n;i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}

	void join(int a, int b) {
		int groupA = find(a);
		int groupB = find(b);
		if(groupA == groupB) return;
		
		parent[groupA] = groupB;
	}

	int find(int v) {
		if(v == parent[v]) {
			return v;
		}

		return parent[v] = find(parent[v]);
	}

	bool isSameGroup(int a, int b) {
		return find(a) == find(b);
	}

private:
	int parent[maxn];
	int sz[maxn];
};

double findDist(ii a, ii b) {
	return sqrt((a.first - b.first)*(a.first-b.first) + (a.second-b.second) * (a.second - b.second));
}

void solve(){
	int n;

	int tt = 1;
	while(scanf("%d",&n), n) {
		vdii edgeList;
		vii coordinates(n+1);
		vi cnt(n+1);

		ll sumPenduduk = 0;

		for(int i=0;i<n;i++){
			int r,c, num;
			scanf("%d%d%d",&r,&c,&num);
			coordinates[i] = {r, c};
			cnt[i] = num;
			sumPenduduk += num;
		}



		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				double dist = findDist(coordinates[i], coordinates[j]);
				edgeList.pb(dii(dist, ii(i,j)));
			}
		}

		UFDS uf(n);

		bool isVisited[n];
		memset(isVisited, false, sizeof(isVisited));
		isVisited[0] = true;

		double sumPembilang = 0;

		sort(edgeList.begin(), edgeList.end());
		for(int i=0;i<edgeList.size();i++){
			dii edge = edgeList[i];
			double dist = edge.first;
			int u = edge.second.first, v = edge.second.second;
			if(uf.isSameGroup(u, v)) {
				continue;
			}

			uf.join(u,v);
			for(int j=0;j<n;j++){
				if(!isVisited[j] && uf.isSameGroup(0, j)) {
					//calculate the time
					double daysNeeded = dist;
					sumPembilang += (daysNeeded * cnt[j]);
					isVisited[j] = true;
				}
			}
		}

		printf("Island Group: %d Average %.2lf\n\n", tt++, sumPembilang / sumPenduduk);
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