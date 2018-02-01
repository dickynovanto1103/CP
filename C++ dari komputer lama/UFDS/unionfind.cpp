#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;

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
	int i;
	UnionFind UF(5);//making initial state..5 nodes are all disjoint
	printf("numDisjointSet: %d\n",UF.numDisjointSet());
	UF.unionSet(0,1);
	printf("numDisjointSet: %d\n",UF.numDisjointSet());
	UF.unionSet(2,3);
	printf("numDisjointSet: %d\n",UF.numDisjointSet());
	UF.unionSet(4,3);
	printf("numDisjointSet: %d\n",UF.numDisjointSet());
	printf("isSameSet(0,3) = %d\n",UF.isSameSet(0,3));
	printf("isSameSet(0,1) = %d\n",UF.isSameSet(0,1));
	printf("isSameSet(2,3) = %d\n",UF.isSameSet(2,3));
	printf("isSameSet(3,4) = %d\n",UF.isSameSet(3,4));


	for(i=0;i<5;i++){printf("findSet(%d) = %d, sizeSetOf(%d) = %d\n",i,UF.findSet(i),i,UF.sizeSetOf(i));}
	UF.unionSet(0,3);

	printf("numDisjointSet: %d\n",UF.numDisjointSet());
	for(i=0;i<5;i++){printf("findSet(%d) = %d, sizeSetOf(%d) = %d\n",i,UF.findSet(i),i,UF.sizeSetOf(i));}
	return 0;
}