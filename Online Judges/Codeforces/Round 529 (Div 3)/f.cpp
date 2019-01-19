#include <bits/stdc++.h>

using namespace std;
#define inf 10000000000000LL
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
typedef pair<ll, ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int maxn = 2e5 + 5;

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

ll a[maxn];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	UnionFind UF(maxn);
	vector<iii> edgeList;

	ll idMurah, palingMurah = inf;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);

		if(palingMurah > a[i]){
			palingMurah = a[i];
			idMurah = i;
		}
	}
	ll harga[maxn];
	int x[maxn], y[maxn];
	ll ans = 0;
	for(i=0;i<m;i++){
		scanf("%d %d %lld",&x[i],&y[i], &harga[i]);
		edgeList.pb(make_pair(harga[i], ii(x[i], y[i])));
		

	}
	for(i=1;i<=n;i++){
		if(i != idMurah){
			edgeList.pb(make_pair(a[i] + a[idMurah], ii(idMurah, i)));
		}
	}
	sort(edgeList.begin(), edgeList.end());
	for(i=0;i<edgeList.size();i++){
		iii front = edgeList[i];
		ll harga = front.first;
		int node1 = front.second.first, node2 = front.second.second;
		if(!UF.isSameSet(node1, node2)) {
			UF.unionSet(node1, node2);
			ans += harga;
		}
	}
	printf("%lld\n",ans);
	return 0;
};