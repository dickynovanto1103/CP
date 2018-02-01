#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dist1,dist2;
int main(){
	int n,m,s,t,p;
	int awal[100000],akhir[100000],w[100000],i,j;
	int tc;
	ll ans;
	queue <int> q;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
		AdjList.assign(n+1,vii()); dist1.assign(n+1,inf); dist2.assign(n+1,inf);
		for(i=0;i<m;i++){
			scanf("%d %d %d",&awal[i],&akhir[i],&w[i]);
			int a = awal[i],b = akhir[i];
			AdjList[a].push_back(ii(b,w[i]));
		}
		//from source
		dist1[s]=0;
		priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,s));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if(d > dist1[u]) continue;
			for(i=0;i<AdjList[u].size();i++){
				ii v = AdjList[u][i];
				if(v.second + dist1[u] < dist1[v.first]){
					dist1[v.first] = dist1[u] + v.second;
					pq.push(ii(dist1[v.first], v.first));
				}
			}
		}
		//from destination
		AdjList.clear();
		AdjList.assign(n+1,vii());
		for(i=0;i<m;i++){
			int a = awal[i],b = akhir[i];
			AdjList[b].push_back(ii(a,w[i]));
		}
		dist2[t]=0; pq.push(ii(0,t));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			for(i=0;i<AdjList[u].size();i++){
				ii v = AdjList[u][i];
				if(v.second + dist2[u] < dist2[v.first]){
					dist2[v.first] = dist2[u] + v.second;
					pq.push(ii(dist2[v.first], v.first));
				}
			}
		}
		//trying all edges
		ans = -1;
		for(i=0;i<m;i++){
			if(dist1[awal[i]] + w[i] + dist2[akhir[i]] <=p){ans = max(ans,(ll)w[i]);}
		}

		if(ans==-1){printf("-1\n");}
		else{printf("%lld\n",ans);}
		dist1.clear(); dist2.clear(); AdjList.clear();
	}
	return 0;
}