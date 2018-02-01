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

vector<vi> AdjList;

int main() {
	int V,E,i,j,a,b,q;
	scanf("%d %d",&V,&E);
	AdjList.assign(V+1,vi());
	while(E--){
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&a,&b);
		int cnt = 0;
		map<int,int> mapper;
		map<int,int>::iterator it;
		int ans = 0;
		for(i=0;i<AdjList[a].size();i++){
			int v = AdjList[a][i];
			it=mapper.find(v);
			if(it==mapper.end()){mapper[v] = cnt++;}
			//else{cnt++;}
		}
		for(i=0;i<AdjList[b].size();i++){
			int v = AdjList[b][i];
			it=mapper.find(v);
			if(it!=mapper.end()){ans++;}
		}
		printf("%d\n",ans);
	}
	return 0;
}