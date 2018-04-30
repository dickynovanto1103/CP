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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

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

vector<vii> AdjList;
vector<iii> EdgeList;

bool cmp(ii a, ii b){
	if(a.first == b.first){return a.second < b.second;}
	return a.first < b.first;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vii());
	

	for(i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		EdgeList.pb(make_pair(w,ii(u,v)));
		AdjList[u].pb(ii(v,w)); AdjList[v].pb(ii(u,w));
	}

	//bikin mst dulu
	int mst = 0;
	UnionFind UF(n+1);

	vii listEdgeMST;

	sort(EdgeList.begin(), EdgeList.end());
	set<ii> s;

	for(i=0;i<m;i++){
		iii front = EdgeList[i];
		int berat = front.first, u = front.second.first, v = front.second.second;
		// printf("i: %d u: %d v: %d berat: %d\n",i,u,v,berat);
		if(!UF.isSameSet(u,v)) {
			UF.unionSet(u,v);
			mst+=berat;
			listEdgeMST.pb(ii(min(u,v), max(u,v)));
			s.insert(ii(min(u,v), max(u,v)));
		}
	}


	sort(listEdgeMST.begin(), listEdgeMST.end(), cmp);
	// printf("edge awal\n");
	// for(i=0;i<listEdgeMST.size();i++){
	// 	if(i){printf(" ");}
	// 	printf("%d %d\n",listEdgeMST[i].first,listEdgeMST[i].second);
	// }
	// printf("\n");
	// printf("mst: %d\n",mst);
	ll ans = 0;
	//iterasi edge satu"
	for(i=0;i<m;i++){
		iii front = EdgeList[i];
		int berat = front.first, u = front.second.first, v = front.second.second;
		// printf("u: %d v: %d berat: %d\n",u,v,berat);
		if(s.count(ii(min(u,v), max(u,v)))){
			// printf("masuk sini\n");
			continue;
		}
		//bikin mst
		int mstSekarang = 0;

		UnionFind UF1(n+1);
		UF1.unionSet(min(u,v), max(u,v));

		mstSekarang+=berat;
		vii listEdgeMSTSekarang;
		s.insert(ii(min(u,v), max(u,v)));
		listEdgeMSTSekarang.pb(ii(min(u,v), max(u,v)));
		for(j=0;j<m;j++){
			if(j==i){continue;}
			iii frontSekarang = EdgeList[j];
			int beratSekarang = frontSekarang.first, uSekarang = frontSekarang.second.first, vSekarang = frontSekarang.second.second;
			// printf("i: %d j: %d uSekarang: %d vSekarang: %d beratSekarang: %d\n",i,j,uSekarang, vSekarang, beratSekarang);
			if(!UF1.isSameSet(uSekarang,vSekarang)) {
				UF1.unionSet(uSekarang,vSekarang);
				mstSekarang+=beratSekarang;
				listEdgeMSTSekarang.pb(ii(min(uSekarang,vSekarang), max(uSekarang,vSekarang)));
				// s.insert(ii(min(u,v), max(u,v)));
			}
		}
		// printf("mstSekarang: %d\n",mstSekarang);
		// printf("%d %d\n",listEdgeMST.size(), listEdgeMSTSekarang.size());
		if(mstSekarang == mst){continue;}
		sort(listEdgeMSTSekarang.begin(), listEdgeMSTSekarang.end(), cmp);

		// printf("listEdgeMST\n");
		// for(j=0;j<listEdgeMST.size();j++){
		// 	printf("%d %d\n",listEdgeMST[j].first, listEdgeMST[j].second);
		// }

		// printf("listEdgeMSTSekarang\n");
		// for(j=0;j<listEdgeMSTSekarang.size();j++){
		// 	printf("%d %d\n",listEdgeMSTSekarang[j].first, listEdgeMSTSekarang[j].second);
		// }

		vii listBaru;
		vii::iterator it;
		// printf("halo\n");
		// vi listA, listB, newList;
		// vi::iterator it2;
		// listA.pb(0); listA.pb(2); listA.pb(3); listA.pb(4);
		// listB.pb(1); listB.pb(2); listB.pb(3); listB.pb(4);

		// set_difference(listA.begin(), listA.end(), listB.begin(), listB.end(), inserter(newList, newList.begin()));
		// printf("test\n");
		// newList.resize(it2-newList.begin());
		// printf("newList:\n");
		// for(j=0;j<newList.size();j++){
		// 	if(j){printf(" ");}
		// 	printf("%d",newList[i]);
		// }
		// printf("\n");

		set_difference(listEdgeMST.begin(), listEdgeMST.end(), listEdgeMSTSekarang.begin(), listEdgeMSTSekarang.end(), inserter(listBaru, listBaru.begin()));
		// printf("halo\n");
		// listBaru.resize(it-listBaru.begin());

		// for(j=0;j<listBaru.size();j++){
		// 	if(j){printf(" ");}
		// 	printf("%d %d",listBaru[i].first,listBaru[i].second);
		// }
		// printf("\n");
		ans += listBaru.size();
	}

	printf("%lld\n",ans);
	return 0;
};