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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;


class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

int minimCost[2020];

viii edgeList;
vii listEdge;
vi listVertex;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int x[2020], y[2020];
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	int c[2020], k[2020];
	ll tot = 0;

	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
		minimCost[i] = c[i];
		tot += c[i];
	}

	ll ans = tot;

	for(i=0;i<n;i++){
		scanf("%d",&k[i]);
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			int jarak = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			ll tot = (ll)jarak*(ll)((k[i]+k[j]));
			edgeList.pb(iii(tot, ii(i,j)));
		}
	}
	sort(edgeList.begin(), edgeList.end());
	int ukuran = edgeList.size();
	UnionFind UF(n);
	ll mst = 0;
	ll temp = tot;
	int idxEdge = 0;
	for(i=0;i<ukuran;i++){
		iii pas = edgeList[i];
		ll jarak = pas.first;
		int a = pas.second.first, b = pas.second.second;
		if(!UF.isSameSet(a,b)){
			int id1 = UF.findSet(a);
			int id2 = UF.findSet(b);
			ll awal = minimCost[id1] + minimCost[id2];
			UF.unionSet(a,b);

			int idBaru = UF.findSet(a);
			minimCost[idBaru] = min(minimCost[a], minimCost[b]);
			ll selisih = awal - minimCost[idBaru];
			temp -= selisih;
			listEdge.pb(ii(a,b));
			mst += jarak;
			if(ans > (mst + temp)){
				ans = mst + temp;
				//update listEdge;
				idxEdge = listEdge.size();
			}
			// printf("gabungin a: %d b: %d jarak: %lld mst jd: %lld\n",a,b,jarak,mst);
		}
	}
	UnionFind baru(n);
	vii listEdgeBeneran;
	for(i=0;i<idxEdge;i++){
		listEdgeBeneran.pb(listEdge[i]);
		baru.unionSet(listEdge[i].first, listEdge[i].second);
	}
	vector<vi> adj;
	adj.assign(n+1,vi());
	for(i=0;i<n;i++){
		adj[baru.findSet(i)].pb(i);
	}

	for(i=0;i<n;i++){
		int minCost = inf+1, idx;
		for(j=0;j<adj[i].size();j++){
			int ver = adj[i][j];
			if(minCost > c[ver]){
				minCost = c[ver];
				idx = ver;
			}
		}
		if(minCost == inf + 1){
			continue;
		}else{
			listVertex.pb(idx);
		}
	}



	printf("%lld\n",ans);
	assert(listVertex.size() > 0);
	printf("%d\n",(int)listVertex.size());
	for(i=0;i<listVertex.size();i++){
		if(i){printf(" ");}
		printf("%d",listVertex[i]+1);
	}
	printf("\n%d\n",(int)listEdgeBeneran.size());
	for(i=0;i<listEdgeBeneran.size();i++){
		printf("%d %d\n",listEdgeBeneran[i].first+1,listEdgeBeneran[i].second+1);
	}
	return 0;
};