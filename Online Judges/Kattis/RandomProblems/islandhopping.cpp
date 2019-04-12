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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double, ii> iii;
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

const int maxn = 760;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		double x[maxn], y[maxn];
		vector<iii> edgelist;
		for(i=0;i<n;i++){
			scanf("%lf %lf",&x[i], &y[i]);
		}

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				double jarak = hypot(x[i]-x[j], y[i] - y[j]);
				edgelist.pb(iii(jarak, ii(i,j)));
			}
		}
		sort(edgelist.begin(), edgelist.end());
		UnionFind UF(n);
		double ans = 0;
		for(i=0;i<edgelist.size();i++){
			iii front = edgelist[i];
			double jarak = front.first;
			int x = front.second.first, y = front.second.second;
			if(!UF.isSameSet(x,y)){
				UF.unionSet(x,y);
				ans += jarak;
			}
		}
		printf("%.9lf\n",ans);
	}
	return 0;
};