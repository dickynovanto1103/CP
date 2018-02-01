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
	int n,m,i,j,x[760],y[760],a,b;
	double mst,jarak;
	while(scanf("%d",&n)!=EOF){
		UnionFind UF(n);
		for(i=0;i<n;i++){scanf("%d %d",&x[i],&y[i]);}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				jarak = hypot(x[i]-x[j], y[i]-y[j]);
				EdgeList.push_back(make_pair(jarak,ii(i,j)));
			}
		}
		scanf("%d",&m);
		for(i=0;i<m;i++){scanf("%d %d",&a,&b); a--; b--; UF.unionSet(a,b);}

		sort(EdgeList.begin(),EdgeList.end());
		int E = EdgeList.size();
		mst=0;
		bool terhubung = false;
		for(i=0;i<E && !terhubung;i++){
			iii front = EdgeList[i];
			int node1 = front.second.first, node2 = front.second.second;
			
			if(!UF.isSameSet(node1,node2)){
				mst+=front.first;
				UF.unionSet(node1,node2);
			}
			if(UF.numDisjointSet()==1){terhubung = true;}
		}	
		printf("%.2lf\n",mst);
		EdgeList.clear();
	}
	

	return 0;
}