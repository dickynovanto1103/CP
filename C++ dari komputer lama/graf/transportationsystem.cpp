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
	int tc,n,r,i,j,x[1010],y[1010],k,cnt,a,b,E,totalstate;
	double mstroad,msttrain,jarak;
	map <ii,int> mapper;
	map <ii,int>::iterator it;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		scanf("%d %d",&n,&r);
		cnt=0; totalstate=n;
		UnionFind UF(n);
		for(j=0;j<n;j++){scanf("%d %d",&x[j],&y[j]);mapper[ii(x[j],y[j])]=cnt++;}
		for(j=0;j<n-1;j++){
			for(k=j+1;k<n;k++){
				jarak=hypot(x[j]-x[k],y[j]-y[k]);
				it=mapper.find(ii(x[j],y[j])); a=it->second;
				it=mapper.find(ii(x[k],y[k])); b=it->second;
				EdgeList.push_back(make_pair(jarak,ii(a,b)));
			}
		}
		sort(EdgeList.begin(),EdgeList.end());
		E=n*(n-1)/2;
		mstroad=msttrain=0;
		for(j=0;j<E;j++){
			iii front = EdgeList[j];
			int node1 = front.second.first;
			int node2 = front.second.second;
			//printf("node %d ke %d jarak: %.2lf\n",node1,node2,front.first);
			if(!UF.isSameSet(node1,node2)){
				if(front.first<=r){totalstate--;mstroad+=front.first;}
				else{msttrain+=front.first;}
				UF.unionSet(node1,node2);
				//printf("mstroad: %.2lf msttrain: %.2lf\n",mstroad,msttrain);
			}
		}
		int ans1 = (int)round(mstroad);
		int ans2 = (int)round(msttrain);
		printf("Case #%d: %d %d %d\n",i,totalstate,ans1,ans2);
		EdgeList.clear(); mapper.clear();

	}
	return 0;
}