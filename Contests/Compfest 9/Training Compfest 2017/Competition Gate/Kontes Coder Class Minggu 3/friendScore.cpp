#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

set<ii> pendingFriend[50010];
set<ii>::iterator it, it2;
int n;
class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,0); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int parent;
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){
				p[y]=x;
				parent = x;
			}
			else{
				p[x]=y;
				parent = y;
				if(rank[x]==rank[y]){rank[y]++;}
			}
			setSize[parent]+=setSize[(y==parent)? x:y];
			if(pendingFriend[x].size() > pendingFriend[y].size()){
				swap(x,y);
			}
			
			for(it=pendingFriend[x].begin();it!=pendingFriend[x].end();){
				ii temp = *it;
				//printf("temp: %d %d\n",temp.first,temp.second);
				it2 = pendingFriend[y].find(temp);
				
				if(it2!=pendingFriend[y].end()){//ketemu
					//printf("ketemu\n");
					pendingFriend[y].erase(it2);
					pendingFriend[x].erase(it++);
					setSize[parent]++;
					//printf("setSize[%d] jd: %d\n",parent,setSize[parent]);
				}else{
					it++;
					//printf("ga ketemu\n");
				}
			}
			//printf("keluar\n");
			for(it=pendingFriend[x].begin();it!=pendingFriend[x].end();it++){
				ii temp = *it;
				pendingFriend[y].insert(temp);
			}
			pendingFriend[parent] = pendingFriend[y];
			//pendingFriend[x].clear();


		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

int main() {
	int tc,m,i,j,a,b,q;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d %d",&n,&m,&q);
		UnionFind UF(n+1);
		for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			pendingFriend[a].insert(ii(min(a,b),max(a,b))); pendingFriend[b].insert(ii(min(a,b),max(a,b)));
		}
		while(q--){
			int com, idx;
			scanf("%d",&com);
			if(com==1){scanf("%d %d",&a,&b); UF.unionSet(a,b);}
			else{scanf("%d",&idx); printf("%d\n",UF.sizeSetOf(idx));}

		}
		for(i=1;i<=n;i++){pendingFriend[i].clear();}
		
	}
	return 0;
}