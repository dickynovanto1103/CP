#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;

vector<iii> EdgeList;


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
	int V,E,i,j,k;
	int a,b,c,sum;
	while(scanf("%d %d",&V,&E),(V||E)){
		int sum = 0;
		for(i=0;i<E;i++){scanf("%d %d %d",&a,&b,&c); a--;b--; EdgeList.push_back(make_pair(c,ii(a,b))); sum+=c;}
		//kruskal
		int mst = 0;
		sort(EdgeList.begin(), EdgeList.end());
		//reverse(EdgeList.begin(), EdgeList.end());
		UnionFind UF(V);
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int berat = front.first; a = front.second.first; b = front.second.second;
			if(!UF.isSameSet(a,b)){
				mst+=berat;
				//printf("yang gabung: %d %d berat: %d\n",a+1,b+1,berat);
				UF.unionSet(a,b);
			}
		}
		int ans = sum-mst;
		printf("%d\n",ans);
		EdgeList.clear();
	}
	return 0;
}