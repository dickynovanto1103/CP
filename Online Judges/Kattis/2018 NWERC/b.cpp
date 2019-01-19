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

const int maxn = 4e5 + 5;

vector<vi> AdjList;

int val[maxn];
int indegree[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	priority_queue<ii> pq;
	for(i=1;i<=n;i++){
		int banyak;
		scanf("%d %d",&val[i], &banyak);
		if(banyak == 0){
			pq.push(ii(val[i],i));
		}
		indegree[i] = banyak;
		for(j=0;j<banyak;j++){
			int idx;
			scanf("%d",&idx);
			AdjList[idx].pb(i);
		}
	}
	int cnt = 0;
	int ans = 0;
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int nilai = front.first, node = front.second;
		ans = max(ans, nilai+cnt);
		cnt++;
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			indegree[v]--;
			if(indegree[v] == 0){
				pq.push(ii(val[v], v));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};