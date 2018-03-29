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
typedef pair<double,ii> iii;
typedef vector<ii> vii;

vector <iii> EdgeList, EdgeList2;

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
	int tc,i,V,E,u[4952],v[4952],w[4952],j;
	iii front;

	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&V,&E);
		UnionFind UF(V+1);
		for(i=0;i<E;i++){
			scanf("%d %d %d",&u[i],&v[i],&w[i]);
			EdgeList.push_back(make_pair(w[i],ii(u[i],v[i])));
		}
		sort(EdgeList.begin(),EdgeList.end());
		int mst=0;
		for(i=0;i<E;i++){
			front = EdgeList[i];
			if(!UF.isSameSet(front.second.first,front.second.second)){
				mst+=front.first;
				UF.unionSet(front.second.first,front.second.second);
				EdgeList2.push_back(make_pair(front.first,ii(front.second.first,front.second.second)));
			}
		}
		printf("%d ",mst);
		int temp,ans=inf,idx;
		for(i=0;i<EdgeList2.size();i++){
			front = EdgeList2[i];
			UnionFind UF1(V+1);
			EdgeList.clear();
			for(j=0;j<E;j++){//mencari edge yg sesuai dengan EdgeList2[i]
				if(u[j]==front.second.first && v[j]==front.second.second){
					temp=w[j];
					w[j]=inf;
					idx=j;
				}
				EdgeList.push_back(make_pair(w[j],ii(u[j],v[j])));
			}
			sort(EdgeList.begin(),EdgeList.end());
			/*printf("setelah disort:\n");
			for(j=0;j<E;j++){
				front = EdgeList[j];
				int bil = front.first;
				printf("node %d ke node %d beratnya : %d\n",front.second.first,front.second.second, bil);
			}*/
			int mst=0;
			for(j=0;j<E;j++){
				front = EdgeList[j];
				if(!UF1.isSameSet(front.second.first,front.second.second)){
					mst+=front.first;
					UF1.unionSet(front.second.first,front.second.second);
				}
			}
			EdgeList.clear();
			
			ans=min(ans,mst);
			//printf("berat: %d\n",tot);
			w[idx]=temp;//restore berat edge
		}
		printf("%d\n",ans);
		EdgeList2.clear();
		EdgeList.clear();
	}
	return 0;
}