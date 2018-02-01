#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector <int> vi;
typedef long long ll;
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
	int V,E,i,j,a,b,panjang;
	ll ans;
	string kota1,kota2,kota;
	map <string,int> mapper;
	map <string,int>::iterator it;

	while(scanf("%d %d",&V,&E),(V||E)){
		UnionFind UF(V);
		//printf("V: %d, E: %d\n",V,E);
		for(i=0;i<V;i++){cin>>kota; mapper[kota]=i;}
		for(i=0;i<E;i++){
			cin>>kota1>>kota2>>panjang;
			it=mapper.find(kota1); a = it->second;
			it=mapper.find(kota2); b = it->second;
			EdgeList.push_back(make_pair(panjang,ii(a,b)));
			//printf("a: %d b: %d panjang: %d\n",a,b,panjang);
			//printf("i: %d E: %d\n",i,E);
		}
		cin>>kota1;
		sort(EdgeList.begin(),EdgeList.end());
		ans=0;
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int node1 = front.second.first,node2 = front.second.second;
			//printf("a: %d b: %d panjang: %d\n",node1,node2,front.first);
			if(!UF.isSameSet(node1,node2)){
				ans+=front.first; 
				UF.unionSet(node1,node2);
			}
		}
		if(UF.numDisjointSet()>1){printf("Impossible\n");}
		else{printf("%lld\n",ans);}
		EdgeList.clear(); mapper.clear();
	}
	return 0;
}