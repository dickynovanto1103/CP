#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<double,ii> iii;
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
	int tc,i,j,V,numsets,E,req,x[510],y[510],u,v,w;
	bool found;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&req,&V);
		UnionFind UF(V);
		for(i=0;i<V;i++){
			scanf("%d %d",&x[i],&y[i]);
		}
		for(i=0;i<V;i++){
			for(j=i+1;j<V;j++){
				double dist;
				dist = hypot(x[i]-x[j],y[i]-y[j]);
				EdgeList.push_back(make_pair(dist,ii(i,j)));
			}
		}
		sort(EdgeList.begin(),EdgeList.end());

		E=V*(V-1)/2;
		/*for(i=0;i<E;i++){
			iii front=EdgeList[i];
			printf("%.2lf\n",front.first);
		}*/
		double mst=0;
		found=false;
		//int awal = UF.numDisjointSet();
		for(i=0;i<E && !found;i++){
			iii front=EdgeList[i];
			if(!UF.isSameSet(front.second.first,front.second.second)){
				mst=front.first;
				UF.unionSet(front.second.first,front.second.second);
				numsets=UF.numDisjointSet();
				//printf("numset sekarang: %d\n",numsets);
				if(numsets==req){found=true;}
			}
		}
		printf("%.2lf\n",mst);
		EdgeList.clear();
	}
	return 0;
}