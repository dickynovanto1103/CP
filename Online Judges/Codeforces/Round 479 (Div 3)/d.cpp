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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi listAns;
ll a[111];
void dfs(int node){
	listAns.pb(a[node]);
	// printf("node: %d\n",node);
	for(int i=0;i<AdjList[node].size();i++){
		int v =AdjList[node][i];

		dfs(v);
	}
}

int main(){
	int n,i,j;
	map<ll, int> mapper;
	
	// printf("%lld\n",3000000000000000000LL*2LL);
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	int cnt  = 0;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(mapper.find(a[i]) == mapper.end()){
			mapper[a[i]] = cnt++;
		}
	}
	int indegree[110];
	memset(indegree,0,sizeof indegree);
	for(i=0;i<n;i++){
		int idx1 = mapper[a[i]];
		if(a[i]%3LL==0LL){
			ll hasilBagi = a[i] / 3LL;
			if(mapper.find(hasilBagi) != mapper.end()){
				
				int idx2 = mapper[hasilBagi];
				AdjList[idx1].pb(idx2);
				indegree[idx2]++;
			}
		}
		ll hasilKali = a[i]*2LL;

		if(mapper.find(hasilKali) != mapper.end()){
			int idx2 = mapper[hasilKali];
			AdjList[idx1].pb(idx2);
			indegree[idx2]++;
		}
		
	}
	for(i=0;i<n;i++){
		int idx = mapper[a[i]];
		if(indegree[idx]==0){
			dfs(idx);
		}
	}
	for(i=0;i<listAns.size();i++){
		if(i){printf(" ");}
		printf("%lld",listAns[i]);
	}
	printf("\n");
	return 0;
};