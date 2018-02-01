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
	int tc,n,i,j,bil,test=1;
	char c1,c2;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		printf("Case %d:\n",test++);
		UnionFind UF(n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j==0){scanf("%d",&bil);}
				else{scanf(", %d",&bil);}
				if(bil>0){EdgeList.push_back(make_pair(bil,ii(i,j)));}
			}
		}
		sort(EdgeList.begin(),EdgeList.end());
		for(i=0;i<EdgeList.size();i++){
			iii front = EdgeList[i];
			int node1 = front.second.first,node2 = front.second.second;
			if(!UF.isSameSet(node1,node2)){
				UF.unionSet(node1,node2);
				node1+=65; node2+=65;
				c1 = node1; c2 = node2;
				printf("%c-%c %d\n",c1,c2,front.first);

			}
			//printf("node1 : %d node2: %d berat: %d\n",node1,node2,front.first);
		}

		EdgeList.clear();
	}
	return 0;
}