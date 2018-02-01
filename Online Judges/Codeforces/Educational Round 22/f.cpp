#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef pair<int,int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	AdjList.assign(n+1,vi());
	map<ii,int> mapper;
	map<ii,int>::iterator it;
	AdjList.clear();
	mapper.clear();
	int cnt = 0;
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		int maks = max(a,b), minim = min(a,b);
		it=mapper.find(ii(maks,minim));
		if(it==mapper.end()){
			//printf("ga ketemu\n");
			mapper[ii(maks,minim)] = cnt++;
			AdjList[a].push_back(b); AdjList[b].push_back(a);
		}else{
			//printf("ketemu\n");
			mapper.erase(it);
		}
		//printf("test\n");
		//tentukan apakah bipartite
		it = mapper.begin();
		ii coba = (it)->first;
		//printf("a: %d b: %d\n",coba.first,coba.second);
		int s = coba.first;
		queue<int> q; q.push(s);
		vi color(n+1,inf); color[s] = 0;
		bool isbipartite = true;
		while(!q.empty() && isbipartite){
			int u = q.front(); q.pop();
			for(int j=0;j<AdjList[u].size();j++){
				int v = AdjList[u][j];
				a = max(u,v); b = min(u,v);
				it= mapper.find(ii(a,b));
				if(it!=mapper.end()){
					if(color[v]==inf){
						color[v] = 1-color[u];
						q.push(v);
					}else if(color[v]==color[u]){isbipartite=false; break;}
				}
				
			}
		}

		if(isbipartite){printf("YES\n");}
		else{printf("NO\n");}


	}
	return 0;
}