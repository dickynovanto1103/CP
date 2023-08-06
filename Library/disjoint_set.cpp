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

struct UFDS {
	UFDS(int n) {
		for(int i=0;i<n;i++){
			parent[i] = i;
			size[i] = 1;
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

private:
	int parent[1000];
	int sz[1000];
};

int main(){
	
	
	return 0;
};