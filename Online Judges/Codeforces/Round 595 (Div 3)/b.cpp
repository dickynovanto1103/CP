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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
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


int main(){
	int tc,i,j;
	int n;
	scanf("%d",&tc);
	int a[200010];
	bool vis[200001];
	while(tc--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			vis[i] = false;
		}
		UnionFind UF(n+1);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int cur;
		for(i=1;i<=n;i++){
			if(!vis[a[i]]){
				cur = a[i];
				int node = cur;
				vis[cur] = true;
				while(true){
					if(vis[a[node]]){
						break;
					}else{
						vis[a[node]] = true;
						UF.unionSet(cur, a[node]);
						node = a[node];
					}
				}
			}
		}

		for(i=1;i<=n;i++){
			printf("%d ",UF.sizeSetOf(i));
		}
		printf("\n");

	}
	return 0;
};