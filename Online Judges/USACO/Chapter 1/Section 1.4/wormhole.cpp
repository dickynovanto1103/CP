/*
ID: dickyno1
LANG: C++14
TASK: wormhole
*/

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

ll fac[15];

void factorial(int n = 12) {
	fac[0] = 1;
	for(ll i=1;i<=n;i++){
		fac[i] = i * fac[i-1];
	}
}

ll c(ll a, ll b){
	return fac[a] / fac[b] / fac[a - b];
}

int cnt = 0;

int findIdx(vector<bool> taken) {
	int sz = taken.size();
	for(int i=0;i<sz;i++){
		if(!taken[i]){
			return i;
		}
	}

	return -1;
}

vii a;

map<ii, ii> nextNode;
map<ii, ii> pasangan;

bool isCycle(vii v) {
	//try to traverse in every point
	vii nodeList;
	for(int i=0;i<v.size();i++){
		ii pas = v[i];
		ii node1 = a[pas.first];
		ii node2 = a[pas.second];
		pasangan[node1] = node2;
		pasangan[node2] = node1;
		nodeList.pb(node1); nodeList.pb(node2);
	}
	
	for(ii node: nodeList) {
		map<ii, bool> vis;
		while(node != ii(-1,-1)) {
			ii pasa = pasangan[node];
			node = nextNode[pasa];
			if(node != ii(-1,-1) && vis[node]) {
				return true;
			}
			vis[node] = true;
		}
	}

	return false;
}

void recurse(int idx, vector<bool> taken, vii v) {
	if(idx == -1) {
		if(isCycle(v)) {
			// for(ii g: v) {
			// 	ii node1 = a[g.first];
			// 	ii node2 = a[g.second];
			// 	printf("(%d,%d) -> (%d, %d) ", node1.first, node1.second, node2.first, node2.second);
			// }
			// puts("");
			cnt++;
		}

		return;
	}
	taken[idx] = true;
	int sz = taken.size();
	for(int i=idx+1;i<sz;i++){
		if(taken[i]) continue;
		//pick i or not pick i

		taken[i] = true;
		int newIdx = findIdx(taken);
		v.pb(ii(idx, i));
		recurse(newIdx, taken, v);
		if(i == sz - 1){continue;}

		v.pop_back();
		taken[i] = false;
	}
}

bool cmp(ii a, ii b) {
	if(a.second == b.second) {
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main(){
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);

	int n, i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a.pb(ii(x,y));
		nextNode[ii(x,y)] = ii(-1,-1);
	}

	sort(a.begin(), a.end(), cmp);
	for(i=0;i<n-1;i++){
		if(a[i].second == a[i+1].second) {
			nextNode[a[i]] = a[i+1];
		}
	}

	vector<bool> taken(n);
	// taken[0] = true;
	vii v;
	recurse(0, taken, v);
	printf("%d\n", cnt);
	
	return 0;
};