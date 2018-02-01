#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vector<vii> AdjList, AdjList1;
vi distFront, distBack;
int main(){
	int n,m,q,i;
	scanf("%d %d %d",&n,&m,&q);
	AdjList1.assign(n,vii()); AdjList.assign(n,vii());
	distFront.assign(n,inf); distBack.assign(n,inf);
	for(i=0;i<m;i++){
		ll a,b;
		ll w;
		scanf("%lld %lld %lld",&a,&b,&w);
		AdjList[a].pb(ii(b,w)); AdjList1[b].pb(ii(a,w));
	}
	// printf("depan:\n");
	// for(i=0;i<n;i++){
	// 	printf("node: %d:", i);
	// 	for(int j=0;j<AdjList[i].size();j++){
	// 		int v = AdjList[i][j].first;
	// 		printf(" %d",v);
	// 	}
	// 	printf("\n");
	// }
	// printf("belakang:\n");
	// for(i=0;i<n;i++){
	// 	printf("node: %d:", i);
	// 	for(int j=0;j<AdjList1[i].size();j++){
	// 		int v = AdjList1[i][j].first;
	// 		printf(" %d",v);
	// 	}
	// 	printf("\n");
	// }
	priority_queue<ii, vii, greater<ii> > pq;
	distFront[0] = (ll)0; 
	pq.push(ii(distFront[0],(ll)0));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		ll d = front.first, u = front.second;
		if(d>distFront[u]){continue;}
		for(i=0;i<AdjList[u].size();i++){
			ii v = AdjList[u][i];
			ll node = v.first, berat = v.second;
			if((distFront[u] + berat) < distFront[node]){
				distFront[node] = distFront[u] + berat;
				pq.push(ii(distFront[node],node));
			}
		}
	}

	distBack[n-1] = 0; 
	pq.push(ii(distBack[n-1],(ll)n-1));
	while(!pq.empty()){
		//printf("masuk\n");
		ii front = pq.top(); pq.pop();
		ll d = front.first, u = front.second;
		if(d>distBack[u]){continue;}
		for(i=0;i<AdjList1[u].size();i++){
			ii v = AdjList1[u][i];
			ll node = v.first, berat = v.second;
			if((distBack[u] + berat) < distBack[node]){
				distBack[node] = distBack[u] + berat;
				pq.push(ii(distBack[node],node));
			}
		}
	}

	// printf("jarak dari depan:\n");
	// for(i=0;i<n;i++){
	// 	printf("distFront[%d]: %lld\n",i,distFront[i]);
	// }
	// printf("jarak dari belakang:\n");
	// for(i=0;i<n;i++){
	// 	printf("distBack[%d]: %lld\n",i,distBack[i]);
	// }

	for(i=0;i<q;i++){
		ll a,b,w;
		scanf("%lld %lld %lld",&a,&b,&w);
		ll jarakSekarang = distFront[a] + w + distBack[b];
		if(jarakSekarang<distFront[n-1]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
};