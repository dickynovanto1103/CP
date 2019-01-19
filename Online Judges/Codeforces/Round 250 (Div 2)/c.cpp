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

const int maxn = 1e3 + 3;

bool cmp(ii a, ii b){
	return a.first > b.first;
}

vector<vi> AdjList;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	ii a[maxn];
	int price[maxn];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		price[i] = a[i].first;
		a[i].second = i;
	}

	AdjList.assign(maxn, vi());

	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	sort(a+1,a+n+1, cmp);
	bool isVisited[maxn];
	memset(isVisited, false, sizeof isVisited);
	ll ans = 0;
	for(i=1;i<=n;i++){
		int node = a[i].second;
		// printf("node: %d harga: %d\n",node, a[i].first);
		isVisited[node] = true;
		for(j=0;j<AdjList[node].size();j++){
			int v = AdjList[node][j];
			if(!isVisited[v]){
				ans += (ll)price[v];
				// printf("ditambah: %d\n",price[v]);	
			}
			// printf("v: %d\n",v);
			
		}
	}
	printf("%lld\n",ans);
	return 0;
};