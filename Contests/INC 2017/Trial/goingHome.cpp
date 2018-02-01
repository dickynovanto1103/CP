#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vector<vii> AdjList, AdjList1;
vi front,back;

int main() {
	int tc,i,q,j;
	ll V,E;
	/*scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n",tt);*/
		scanf("%lld %lld %d",&V,&E,&q);
		AdjList.assign(V,vii());
		AdjList1.assign(V,vii());
		while(E--){
			ll u,v,w;
			scanf("%lld %lld %lld",&u,&v,&w);
			AdjList[u].pb(ii(v,w)); AdjList1[v].pb(ii(u,w));
		}
		/*for(i=0;i<V;i++){
			printf("node %d:");
			for(j=0;j<AdjList[i].size();j++){
				ii pas = AdjList[i][j];
				printf(" %d (%d)",pas.first,pas.second);
			}
			printf("\n");
		}*/

		front.assign(V,inf); front[0] = 0;
		priority_queue<ii, vii, greater<ii> > pq; pq.push(ii((ll)0,(ll)0));
		while(!pq.empty()){
			ii a = pq.top(); pq.pop();
			int d = a.first, u = a.second;
			if(d>front[u]){continue;}
			for(int i=0;i<AdjList[u].size();i++){
				ii pas = AdjList[u][i];
				if(front[pas.first] > pas.second + front[u]){
					front[pas.first] = pas.second + front[u];
					pq.push(ii(front[pas.first], pas.first));
				}
			}
		}
		/*printf("dist from 0:\n");
		for(i=0;i<V;i++){
			printf("dist[%d]: %d\n",i,front[i]);
		}*/
		back.assign(V,inf); back[V-1] = 0;
		pq.push(ii((ll)0,V-1));
		while(!pq.empty()){
			ii a = pq.top(); pq.pop();
			int d = a.first, u = a.second;
			if(d>back[u]){continue;}
			for(int i=0;i<AdjList1[u].size();i++){
				ii pas = AdjList1[u][i];
				if(back[pas.first] > pas.second + back[u]){
					back[pas.first] = pas.second + back[u];
					pq.push(ii(back[pas.first], pas.first));
				}
			}
		}
		/*printf("dist from %d:\n",V-1);
		for(i=0;i<V;i++){
			printf("dist[%d]: %lld\n",i,back[i]);
		}
		printf("front[%lld]: %lld\n",V-1,front[V-1]);*/
		while(q--){
			ll u,v,w;
			scanf("%lld %lld %lld",&u,&v,&w);
			/*printf("w yang dibaca: %lld\n",w);
			printf("front[%lld]: %lld, back[%lld]: %lld, w: %lld\n",u,front[u],v,back[v],w);*/
			ll ch = front[u] + w + back[v];
			if(ch < front[V-1]){printf("YES\n");}
			else{printf("NO\n");}
		}

		AdjList.clear(); AdjList1.clear();
		front.clear(); back.clear();
	//}
	return 0;
}