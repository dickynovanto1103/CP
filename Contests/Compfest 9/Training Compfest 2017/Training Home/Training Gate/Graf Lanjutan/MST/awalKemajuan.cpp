#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ii> iii;
typedef vector<ii> vii;

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
	vector<iii> EdgeList;
	int n,m,i,j,a,b;
	ll w;
	scanf("%d %d",&n,&m);
	UnionFind UF(n+1);
	for(i=0;i<m;i++){scanf("%d %d %lld",&a,&b,&w); EdgeList.pb(make_pair(w,ii(a,b)));}
	sort(EdgeList.begin(),EdgeList.end());
	ll mst = 0;
	for(i=0;i<m;i++){
		iii front = EdgeList[i];
		ll berat = front.first;
		int x = front.second.first, y = front.second.second;
		if(!UF.isSameSet(x,y)){
			mst+=berat;
			UF.unionSet(x,y);
		}
	}
	printf("%lld\n",mst);
	return 0;
}