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

struct state {
	int numCity;
	int numPower;
};

int par[200010];
state states[200010];

int curConnected = 0;

class UFDS {
public:
	UFDS(int n, int m) {
		for(int i=1;i<=n + m;i++) {
			par[i] = i;
		}

		for(int i=1;i<=n;i++){
			states[i].numCity = 1;
			states[i].numPower = 0;
		}

		for(int i=n+1;i<=n+m;i++){
			states[i].numCity = 0;
			states[i].numPower = 1;
		}
	}

	int findSet(int i) {
		if(par[i] == i) return i;
		return par[i] = findSet(par[i]);
	}

	void combine(int a, int b) {
		int group1 = findSet(a);
		int group2 = findSet(b);

		if(group1 == group2) return;

		state state1 = states[group1], state2 = states[group2];
		
		state newState;
		newState.numCity = state1.numCity + state2.numCity;
		newState.numPower = state1.numPower + state2.numPower;

		par[group1] = group2;
		states[group1] = newState;
		states[group2] = newState;

		if(state1.numPower > 0 && state2.numPower > 0) {
			//do nothing, no need to add num of connected cities
		}else if(state1.numPower > 0 || state2.numPower > 0) {
			if(state1.numPower == 0) {
				curConnected += state1.numCity;
			}else if(state2.numPower == 0) {
				curConnected += state2.numCity;
			}else{
				assert(false);
			}
		}
	}
};

ii edges[500010];
int que[500010];
bool isDestroyed[500010];

int main(){
	int n,m,e;
	scanf("%d %d %d",&n,&m,&e);
	for(int i=0;i<e;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edges[i].first = a, edges[i].second = b;
	}

	int q;
	scanf("%d",&q);
	memset(isDestroyed, false, sizeof isDestroyed);
	for(int i=0;i<q;i++){
		scanf("%d",&que[i]);
		isDestroyed[que[i]-1] = true;
	}

	UFDS UF(n, m);
	for(int i=0;i<e;i++){
		if(isDestroyed[i]) continue;
		UF.combine(edges[i].first, edges[i].second);
	}

	vi ans;
	ans.pb(curConnected);
	for(int i=q-1;i>=1;i--){
		int idx = que[i] - 1; 
		UF.combine(edges[idx].first, edges[idx].second);
		ans.pb(curConnected);
	}

	reverse(ans.begin(), ans.end());
	for(int val: ans) {
		printf("%d\n", val);
	}
	
	return 0;
};