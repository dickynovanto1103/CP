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
	int tc,V,E,i,j,w,cnt,a,b;
	map <string,int> mapper;
	map <string,int>::iterator it;
	char kota1[10],kota2[10];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&V,&E);
		UnionFind UF(V);
		cnt=0;
		for(i=0;i<E;i++){
			scanf("%s %s %d",kota1,kota2,&w);
			it=mapper.find((string)kota1);
			if(it==mapper.end()){mapper[(string)kota1]=cnt++;}
			it=mapper.find((string)kota2);
			if(it==mapper.end()){mapper[(string)kota2]=cnt++;}
			it=mapper.find((string)kota1); a=it->second;
			it=mapper.find((string)kota2); b=it->second;
			EdgeList.push_back(make_pair(w,ii(a,b)));
		}
		sort(EdgeList.begin(),EdgeList.end());
		int mst=0;
		for(i=0;i<E;i++){
			iii front=EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst+=front.first;
				UF.unionSet(front.second.first,front.second.second);
			}
		}
		printf("%d\n",mst);
		EdgeList.clear();
		mapper.clear();
		if(tc){printf("\n");}
	}
	return 0;
}