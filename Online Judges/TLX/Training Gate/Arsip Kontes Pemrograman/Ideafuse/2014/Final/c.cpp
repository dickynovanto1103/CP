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
typedef pair<int,ii> iii;
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

vector<vii> AdjList;

bool cmp(iii a, iii b){
	return a.first > b.first;
}

int main(){
	int n,m,i,j,tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++) {
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&m);
		ll beratTotal = 0;
		for(i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			beratTotal+=(ll)c;
			EdgeList.pb(make_pair(c,ii(a,b)));
		}
		// printf("beratTotal: %lld\n",beratTotal);
		sort(EdgeList.begin(), EdgeList.end(), cmp);
		UnionFind UF(n+1);
		ll mst = 0;
		for(i=0;i<m;i++){
			iii data = EdgeList[i];
			int berat = data.first, a = data.second.first, b = data.second.second;
			if(!UF.isSameSet(a,b)) {
				UF.unionSet(a,b);
				mst+=(ll)berat;
				// printf("berat yang ditambah: %d gabungin %d dengan %d mst jd: %lld\n",berat,a,b,mst);
			}
		}
		printf("%lld\n",beratTotal - mst);
		EdgeList.clear();
	}
	return 0;
};