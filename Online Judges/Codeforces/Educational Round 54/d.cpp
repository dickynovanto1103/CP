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
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ii> vii;

const int maxn = 3e5 + 5;

vector<vii> AdjList;

ll dist[maxn];

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	map<ii, int> mapper;
	AdjList.assign(maxn, vii());
	for(i=0;i<m;i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		int minim = min(a,b), maks = max(a,b);
		mapper[ii(minim, maks)] = i+1;
		// mapper[ii(a,b)] = i+1; mapper[ii(b,a)] = i+1;
		AdjList[a].pb(ii(b,w));
		AdjList[b].pb(ii(a,w));
	}
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	for(i=0;i<maxn;i++){
		dist[i] = inf;
	}
	dist[1] = 0;
	pq.push(make_pair(dist[1], 1));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		ll jarak = front.first, node = front.second;
		
		if(dist[node] < jarak){continue;}
		for(i=0;i<AdjList[node].size();i++){
			ii v = AdjList[node][i];
			if(dist[node] + v.second < dist[v.first]){
				dist[v.first] = dist[node] + v.second;
				pq.push(make_pair(dist[v.first], v.first));
			}
		}
	}
	queue<int> q;
	q.push(1);
	int jumlahEdge = 0;
	bool isVisited[maxn], isVisitedNode[maxn];
	memset(isVisitedNode, false, sizeof isVisitedNode);
	isVisitedNode[1] = true;
	vi listAns;
	// printf("k: %d\n",k);
	while(!q.empty()){
		if(jumlahEdge == k){break;}
		int front = q.front(); q.pop();
		for(i=0;i<AdjList[front].size();i++){
			ii v = AdjList[front][i];
			if(dist[v.first] == dist[front] + v.second){
				if(isVisitedNode[v.first]){continue;}

				int minim = min(front, (int)v.first), maks = max(front, (int)v.first);

				int idxEdge = mapper[ii(minim, maks)];
				listAns.pb(idxEdge);
				isVisitedNode[v.first] = true;
				jumlahEdge++;
				if(jumlahEdge == k){break;}
				q.push(v.first);
			}
		}
		if(jumlahEdge == k){break;}
	}
	printf("%d\n",jumlahEdge);
	for(i=0;i<jumlahEdge;i++){
		if(i){printf(" ");}
		printf("%d",listAns[i]);
	}
	printf("\n");
	return 0;
};	