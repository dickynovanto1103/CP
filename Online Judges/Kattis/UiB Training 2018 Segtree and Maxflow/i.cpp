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

const int maxn = 10100;
vector<vi> AdjList;

vi match, vis;

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
	ll x[2501],y[2501];
	scanf("%d",&n);
	AdjList.assign(maxn,vi());
	int cnt = n+1;
	for(i=1;i<=n;i++){
		scanf("%lld %lld",&x[i],&y[i]);
		ll tambah = x[i] + y[i];
		if(mapper.find(tambah) == mapper.end()){
			mapper[tambah] = cnt;
			arr[cnt] = tambah;
			cnt++;
		}
		int idx = mapper[tambah];
		AdjList[i].pb(idx);
		// printf("%lld %lld connect ke arr[%d]: %d\n",x[i], y[i], idx, arr[idx]);
		ll kurang = x[i] - y[i];
		if(mapper.find(kurang) == mapper.end()){
			mapper[kurang] = cnt;
			arr[cnt] = kurang;
			cnt++;
		}
		idx = mapper[kurang];
		AdjList[i].pb(idx);
		ll kali = x[i] * y[i];
		if(mapper.find(kali) == mapper.end()){
			mapper[kali] = cnt;
			arr[cnt] = kali;
			cnt++;
		}
		idx = mapper[kali];
		AdjList[i].pb(idx);
	}
	int mcbm = 0;
	match.assign(maxn,-1);
	for(i=1;i<=n;i++){
		vis.assign(maxn,0);
		mcbm+=Aug(i);
	}
	int pasangan[maxn];
	memset(pasangan, -1, sizeof pasangan);
	// printf("mcbm: %d\n",mcbm);
	if(mcbm == n){
		for(i=n+1;i<cnt;i++){
			if(match[i] == -1){continue;}
			int idx = match[i];
			pasangan[idx] = i;
		}
		for(i=1;i<=n;i++){
			int idx = pasangan[i];
			ll bil = arr[idx];
			ll bil1 = x[i], bil2 = y[i];
			if((bil1 * bil2) == bil){printf("%lld * %lld = %lld\n",bil1,bil2,bil);}
			else if((bil1 - bil2) == bil){printf("%lld - %lld = %lld\n",bil1,bil2,bil);}
			else if((bil1 + bil2) == bil){printf("%lld + %lld = %lld\n",bil1,bil2,bil);}
		}
	}else{
		printf("impossible\n");
	}

	return 0;
};