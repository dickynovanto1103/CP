#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
typedef long long ll;

vector <iii> EdgeList;

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=1;i<=n;i++){p[i]=i;}
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
	int V,E,i,a,b,c,K,tc=0;
	int u[13],v[13],w[13];
	while(scanf("%d",&V)!=EOF){
		if(tc>0){printf("\n");}

		UnionFind UF(V);
		for(i=0;i<V-1;i++){
			scanf("%d %d %d",&a,&b,&c);
		}
		scanf("%d",&K);
		for(i=0;i<K;i++){
			scanf("%d %d %d",&u[i],&v[i],&w[i]);
		}
		scanf("%d",&E);
		for(i=0;i<E;i++){
			scanf("%d %d %d",&a,&b,&c);
			EdgeList.push_back(make_pair(c,ii(a,b)));
		}
		sort(EdgeList.begin(),EdgeList.end());
		//jawaban 1
		ll mst1=0;
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first,front.second.second)){
				mst1+=front.first;
				UF.unionSet(front.second.first,front.second.second);
			}
		}
		//ditambahin tambahan K edges
		for(i=0;i<K;i++){
			EdgeList.push_back(make_pair(w[i],ii(u[i],v[i])));
		}
		sort(EdgeList.begin(),EdgeList.end());
		//jawaban 2
		UnionFind UF1(V);
		ll mst2=0;
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			if(!UF1.isSameSet(front.second.first,front.second.second)){
				mst2+=front.first;
				UF1.unionSet(front.second.first,front.second.second);
			}
		}
		printf("%lld\n%lld\n",mst1,mst2);
		tc=1;
		EdgeList.clear();
	}
	return 0;
}