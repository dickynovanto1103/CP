#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int maxn = 1001;
const int maxc = 101;

int harga[maxn][maxc];
vector<vii> AdjList;

int main(){
	int n,m,q;
	int a[maxn];
	int i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n,vii());
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		AdjList[u].pb(ii(v,w)); AdjList[v].pb(ii(u,w));
	}
	scanf("%d",&q);
	while(q--){
		int capacity,start,end;
		scanf("%d %d %d",&capacity,&start,&end);
		for(i=0;i<n;i++){
			for(j=0;j<=capacity;j++){
				harga[i][j] = inf;
			}
		}
		//dijkstra
		harga[start][0] = 0;
		priority_queue<iii, vector<iii>, greater<iii> > pq; 
		/*pq.push(make_pair(0,ii(start,0)));
		pq.push(make_pair(3,ii(start,0)));
		pq.push(make_pair(2,ii(start,0)));
		pq.push(make_pair(5,ii(start,0)));
		printf("testing\n");
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			printf("%d\n",front.first);
		}*/
		pq.push(make_pair(harga[start][0],ii(start,0)));
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			int d = front.first;
			int u = front.second.first, cap = front.second.second;
			if(d>harga[u][cap]){continue;}
			if(cap!=capacity){
				if(harga[u][cap+1] > harga[u][cap] + a[u]){
					harga[u][cap+1] = a[u] + harga[u][cap];	
					pq.push(make_pair(harga[u][cap+1],ii(u,cap+1)));
				}
				
			}
			
			for(i=0;i<AdjList[u].size();i++){
				ii v = AdjList[u][i];
				int node = v.first, pjg = v.second;
				int selisih;

				if(cap>=pjg){
					selisih = cap-pjg;
					if(harga[node][selisih] > harga[u][cap]){
						harga[node][selisih] = harga[u][cap];
						pq.push(make_pair(harga[node][selisih],ii(node,selisih)));
					}
				}
			}
		}
		int minim = inf;
		for(i=0;i<=capacity;i++){
			minim = min(minim,harga[end][i]);
		}
		if(minim==inf){printf("impossible\n");}
		else{printf("%d\n",minim);}
	}

	return 0;
};