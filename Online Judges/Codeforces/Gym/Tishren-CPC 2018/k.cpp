#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000LL
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
typedef pair<ll, ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int maxn = 1e6;
bool isprime[maxn+12];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

vector<vii> AdjList;

ll costAkhir[1000014];
int cntPrime;

ll cariMinimal(int bil){
	ll hasilAkhir = inf;
	if(costAkhir[bil]!=-1){return costAkhir[bil];}
	for(int i=2;i*i<=bil;i++){
		if(bil%i==0){
			int bil1 = bil/i;
			int bil2 = i;
			if(isprime[bil1]){
				ll jadi = bil/bil1 + bil1*2;
				hasilAkhir = min(hasilAkhir,jadi);
			}
			if(isprime[bil2]){
				ll jadi = bil/bil2 + bil2*2;
				hasilAkhir = min(hasilAkhir, jadi);
			}
		}
	}

	return hasilAkhir;
}

priority_queue<iii, viii, greater<iii> > pq;
ll dist[10014][114];

int main(){
	memset(isprime, true,sizeof isprime);
	sieve(maxn);

	int tc;
	int n,m,k;
	int i,j;

	memset(costAkhir, -1, sizeof costAkhir);

	costAkhir[1] = 2;
	
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d %d",&n,&m,&k);
		AdjList.assign(10010,vii());
		// printf("n: %d m: %d k: %d\n",n,m,k);
		for(i=0;i<m;i++){
			ll a,b;
			ll w;
			scanf("%lld %lld %lld",&a,&b,&w);
			AdjList[a].pb(ii(b,w)); AdjList[b].pb(ii(a,w));
			
			costAkhir[w] = cariMinimal(w);
		}
		
		int awal, akhir;
		scanf("%d %d",&awal,&akhir);
		
		for(i=0;i<=10001;i++){
			for(j=0;j<=101;j++){
				dist[i][j] = inf;
			}
		}

		dist[awal][k] = 0;
		pq.push(make_pair(dist[awal][k], ii(awal,k)));
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			ll jarak = front.first, node = front.second.first, sisaBatu = front.second.second;
			if(dist[node][sisaBatu] < jarak){continue;}

			for(i=0;i<AdjList[node].size();i++){
				// printf("i: %d ukuran AdjList[%lld]: %d\n",i,node, (int)AdjList[node].size());
				ii v = AdjList[node][i];
				ll nodeTetangga = v.first, berat = v.second;
				// printf("nodeTetangga: %lld berat: %lld\n",nodeTetangga, berat);
				if((dist[node][sisaBatu] + berat) < dist[nodeTetangga][sisaBatu]){
					dist[nodeTetangga][sisaBatu] = dist[node][sisaBatu] + (ll)berat;
					pq.push(make_pair(dist[nodeTetangga][sisaBatu], ii(nodeTetangga, sisaBatu)));
				}

				if(sisaBatu >= 1){
					ll beratAkhir = costAkhir[berat];
					if(berat == 1){continue;}
					if(beratAkhir < berat){
						if((dist[node][sisaBatu] + beratAkhir) < dist[nodeTetangga][sisaBatu-1]){
							dist[nodeTetangga][sisaBatu-1] = dist[node][sisaBatu] + beratAkhir;
							pq.push(make_pair(dist[nodeTetangga][sisaBatu-1], ii(nodeTetangga, sisaBatu-1)));
						}	
					}
					
				}
				
			}
		}

		ll ans = inf;
		for(i=0;i<=k;i++){
			ans = min(ans, dist[akhir][i]);
		}
		if(ans==inf){printf("-1\n");}
		else{printf("%lld\n", ans);}
		
		AdjList.clear();
	}

	return 0;
};