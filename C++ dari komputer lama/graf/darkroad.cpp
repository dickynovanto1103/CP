#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector <int> vi;

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
	int V,E,i,j,a,b,weight,mst,ans,total;
	while(scanf("%d %d",&V,&E), (V||E)){
		UnionFind UF(V);
		total=0;
		for(i=0;i<E;i++){
			scanf("%d %d %d",&a,&b,&weight);
			total+=weight;
			EdgeList.push_back(make_pair(weight,ii(a,b)));
		}
		sort(EdgeList.begin(),EdgeList.end());
		mst = 0;
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			a = front.second.first; b=front.second.second;
			if(!UF.isSameSet(a,b)){
				UF.unionSet(a,b);
				mst+=front.first;
			}
		}
		ans = total-mst;
		printf("%d\n",ans);
		EdgeList.clear();
	}
	return 0;
}