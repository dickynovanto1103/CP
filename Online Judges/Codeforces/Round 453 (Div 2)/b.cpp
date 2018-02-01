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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e4 + 5;

vector<vi> AdjList;
int warna[maxn];

ll solve(int node, int color) {
	int i,j;
	ll ans = 0;
	for(i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(warna[v]!=color){
			ans++;
		}
		ans+=solve(v,warna[v]);
	}
	return ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+3,vi());
	for(i=2;i<=n;i++){
		int parent;
		scanf("%d",&parent);
		AdjList[parent].pb(i);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&warna[i]);
	}
	ll ans = 1;
	ans+=solve(1,warna[1]);
	printf("%lld\n",ans);
	return 0;
};