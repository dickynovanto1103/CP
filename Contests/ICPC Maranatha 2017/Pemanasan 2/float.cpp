#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<double,ii> iii;
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

int main() {
	int tc,n,i,j;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		if(test==2){printf("\n");}
		scanf("%d",&n);
		UnionFind UF(n);
		double a[101],b[101];
		for(i=0;i<n;i++){scanf("%lf %lf",&a[i],&b[i]);}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				double jarak = hypot(a[i]-a[j],b[i]-b[j]);
				EdgeList.pb(make_pair(jarak,ii(i,j)));
			}
		}
		sort(EdgeList.begin(),EdgeList.end());
		double mst = 0;
		int E = EdgeList.size();
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			double jarak = front.first;
			int node1 = front.second.first,node2 = front.second.second;
			if(!UF.isSameSet(node1,node2)){
				UF.unionSet(node1,node2);
				mst+=jarak;
			}
		}
		printf("%.2lf\n",mst);
		EdgeList.clear();
		test = 2;
	}
	return 0;
}