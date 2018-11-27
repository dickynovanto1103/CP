#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
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

const int maxn = 210;

vi match, vis;
vector<vi> AdjList;
map<ll, int> mapper;
ll arr[maxn];
int Aug(int node) {
	if(vis[node]){return 0;}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1; // found 1 matching
		}
	}
	return 0; //no matching
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	ll x[maxn], y[maxn];
	for(i=1;i<=2*n;i++){
		scanf("%lld %lld",&x[i],&y[i]);
		// printf("x[%d]: %lld y[%d]: %lld\n",i,x[i],i,y[i]);
	}
	ll kiri = 0, kanan = inf, mid, ans;
	while(kiri <= kanan){
		mid = (kiri+kanan)/2LL;
		AdjList.assign(maxn, vi());
		
		for(i=1;i<=n;i++){
			for(j=n+1;j<=2*n;j++){
				ll jarak = abs(x[i] - x[j]) + abs(y[i] - y[j]);
				if(jarak <= mid){
					AdjList[i].pb(j);
				}
			}
		}
		int mcbm = 0;
		match.assign(maxn,-1);
		for(i=1;i<=n;i++){
			vis.assign(maxn,0);
			mcbm+=Aug(i);
		}
		if(mcbm == n){
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
};