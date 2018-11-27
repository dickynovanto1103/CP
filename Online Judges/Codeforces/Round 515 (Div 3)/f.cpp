#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
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
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;

vector<vii> AdjList;

const int maxn = 2e5 + 5;

bool cmp(ii a, ii b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second > b.second;
}

ll jarak(ii a, ii b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vii());
	map<int,int> mapper;
	set<int> s;
	set<int>::iterator it;
	int x[maxn], y[maxn];
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
		int maks = max(x[i],y[i]);
		s.insert(maks);
	}
	int cnt = 1;
	for(it = s.begin();it!=s.end();it++){
		int bil = *it;
		mapper[bil] = cnt++;
	}
	for(i=0;i<n;i++){
		int maks = max(x[i],y[i]);
		int idx = mapper[maks];
		AdjList[idx].pb(ii(x[i],y[i]));
	}
	ll dp1[maxn], dp2[maxn];
	vector<iiii> endpoints;
	fill(dp1,dp1+cnt,inf); fill(dp2, dp2+cnt,inf);
	// memset(dp1,0,sizeof dp1); memset(dp2, 0, sizeof dp2);
	for(i=1;i<cnt;i++){
		sort(AdjList[i].begin(), AdjList[i].end(), cmp);
		int ukuran = AdjList[i].size();
		endpoints.pb(make_pair(AdjList[i][0], AdjList[i][ukuran-1]));
		// printf("(%d, %d)(%d, %d)\n",AdjList[i][0].first,AdjList[i][0].second,AdjList[i][ukuran-1].first,AdjList[i][ukuran-1].second);
	}
	//dp1 adalah jarak minimal kalo akhirnya di indeks i di endpoint pertama
	ii awal1 = ii(0,0), awal2 = ii(0,0);
	dp1[0] = 0; dp2[0] = 0;
	// printf("cnt: %d\n",cnt);
	for(i=1;i<cnt;i++){
		//hitung buat dp1
		ll jarakLevel = jarak(endpoints[i-1].second, endpoints[i-1].first);
		dp1[i] = min(dp1[i], dp1[i-1] + jarak(awal1, endpoints[i-1].second) + jarakLevel);

		dp1[i] = min(dp1[i], dp2[i-1] + jarak(awal2, endpoints[i-1].second) + jarakLevel);
		dp2[i] = min(dp2[i], dp1[i-1] + jarak(awal1, endpoints[i-1].first) + jarakLevel);
		dp2[i] = min(dp2[i], dp2[i-1] + jarak(awal2, endpoints[i-1].first) + jarakLevel);
		// printf("jarak: %lld\n",jarak(awal1,endpoints[i-1].second));
		// printf("dp1[%d]: %lld dp2[%d]: %lld\n",i,dp1[i],i,dp2[i]);
		awal1 = endpoints[i-1].first, awal2 = endpoints[i-1].second;
		// printf("awal1 jadi: %d %d awal2 jadi: %d %d\n",awal1.first,awal1.second,awal2.first,awal2.second);
		//hitung buat dp2
	}
	printf("%lld\n",min(dp1[cnt-1], dp2[cnt-1]));
	return 0;
};