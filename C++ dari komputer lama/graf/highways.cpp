#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> ii;
typedef pair <double,ii> iii;
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
	int tc,hasbuilt,V,E,cnt,i,j;
	int x[760],y[760];
	int a,b;
	map <ii,int> mapper;
	map <ii,int>::iterator it;
	/*
	scanf("%d %d",&a,&b);
	printf("%lf\n",hypot(a,b));*/
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&V);
		UnionFind UF(V+1);
		for(i=1;i<=V;i++){
			scanf("%d %d",&x[i],&y[i]);
		//	mapper[ii(x[i],y[i])]=cnt++;
		}
		for(i=1;i<=V;i++){
			for(j=i+1;j<=V;j++){
				double ans;
				ans= hypot(x[i]-x[j],y[i]-y[j]);
				EdgeList.push_back(make_pair(ans,ii(i,j)));
			}
		}
		E=V*(V-1)/2;
		scanf("%d",&hasbuilt);
		while(hasbuilt--){
			scanf("%d %d",&a,&b);
			if(!UF.isSameSet(a,b)){
				UF.unionSet(a,b);
			}
		}
		//proses sisa edge
		sort(EdgeList.begin(),EdgeList.end());
		double mst=0;
		for(i=0;i<E;i++){
			iii front=EdgeList[i];
			if(!UF.isSameSet(front.second.first,front.second.second)){
				mst+=front.first;
				printf("%d %d\n",front.second.first,front.second.second);
				UF.unionSet(front.second.first,front.second.second);
			}
		}
		if(mst==0){printf("No new highways need\n");}
		if(tc){printf("\n");}
		EdgeList.clear();
	}
	return 0;
}