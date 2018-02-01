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

vi daftar;

int main(){
	int V,E,i,j,u,v,w;
	while(scanf("%d %d",&V,&E),(V||E)){
		UnionFind UF(V);
		for(i=0;i<E;i++){
			scanf("%d %d %d",&u,&v,&w);
			EdgeList.push_back(make_pair(w,ii(u,v)));
		}
		sort(EdgeList.begin(),EdgeList.end());
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int node1 = front.second.first, node2 = front.second.second;
			if(!UF.isSameSet(node1,node2)){
				UF.unionSet(node1,node2);
			}else{//membentuk siklik
				daftar.push_back(front.first);
			}
		}
		if(daftar.empty()){printf("forest\n");}
		else{
			int n = daftar.size();
			for(i=0;i<n;i++){
				if(i==0){printf("%d",daftar[i]);}
				else{printf(" %d",daftar[i]);}
			}
			printf("\n");
		}
		EdgeList.clear(); daftar.clear();
	}
	return 0;
}