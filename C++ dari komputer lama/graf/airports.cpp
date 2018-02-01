#include <bits/stdc++.h>

using namespace std;
#define inf 2000000000
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector <int> vi;
typedef long long ll;

vector <iii> EdgeList;

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

int main(){
	int V,E,i,air,tc,test=1,u,v,w,disjoint,ansairport;
	ll mst,ansharga;
	scanf("%d",&tc);
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%d %d %d",&V,&E,&air);
		//UnionFind UF(V);
		for(i=0;i<E;i++){scanf("%d %d %d",&u,&v,&w); u--;v--; EdgeList.push_back(make_pair(w,ii(u,v)));}
		sort(EdgeList.begin(),EdgeList.end());

		disjoint = ansairport = V;
		ansharga = inf;
		
		mst=0;
		UnionFind UF1(V);
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int node1 = front.second.first, node2=front.second.second;
			if(front.first>=air){break;}
			//printf("consider node1 : %d and node2: %d with length: %d\n",node1,node2,front.first);
			if(!UF1.isSameSet(node1,node2)){

				mst+=front.first;
				//printf("node1 : %d and node2: %d tergabung dan mst: %lld\n",node1,node2,mst);
				UF1.unionSet(node1,node2);
			}
			
		}
		ll tambahan = UF1.numDisjointSet()*air;
		mst+=tambahan;
		if(ansharga > mst){ansharga = mst; ansairport = UF1.numDisjointSet();}
			
		
		
		
		printf("%lld %d\n",ansharga,ansairport);
		EdgeList.clear();
	}
	return 0;
}