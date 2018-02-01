#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define maxn 40
#define unvisited -1
#define visited 1
typedef vector <int> vi;

vector <vi> AdjList;

int main(){
	int E,v1,a,b,v2,i,j,awal,ttl,tc,cnt,idx1,idx2;
	vi listnode;
	bool found;
	vector <int>::iterator it;
	queue <int> q;
	map <int,int> mapper;
	map <int,int>::iterator it2;
	tc=1;
	
	while(scanf("%d",&E),E){
		idx1=1;
		AdjList.assign(maxn,vi());
		
		for(i=0;i<E;i++){
			scanf("%d %d",&v1,&v2);

			it2=mapper.find(v1);
			if(it2==mapper.end()){listnode.push_back(idx1++); mapper[v1]=idx1-1;}
			it2=mapper.find(v2);
			if(it2==mapper.end()){listnode.push_back(idx1++); mapper[v2]=idx1-1;}
			it2=mapper.find(v1); a=it2->second;
			it2=mapper.find(v2); b=it2->second;
			//printf("node %d mapped: %d, node %d mapped: %d\n",v1,a,v2,b);
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		/*printf("adjlist:\n");
		for(i=1;i<=30;i++){
			printf("node %d: ", i);
			for(int j=0;j<AdjList[i].size();j++){
				printf(" %d",AdjList[i][j]);
			}
			printf("\n");
		}*/
		sort(listnode.begin(),listnode.end());
		it=unique(listnode.begin(),listnode.end());
		listnode.resize(distance(listnode.begin(),it));
		/*printf("listnode awal:");
		for(i=0;i<listnode.size();i++){printf(" %d", listnode[i]);}
		printf("\n");*/
		while(scanf("%d %d",&awal,&ttl),(awal || ttl)){
			found=false;
				//lakukan bfs
			vi dist(maxn,inf);
			int sisattl;
			cnt=0;//untuk menghitung banyaknya yg tidak terkunjungi
			sisattl=ttl;
			it2=mapper.find(awal);
			dist[it2->second]=0;
			q.push(it2->second);
			while(!q.empty()){
				int v=q.front();q.pop();
				for(i=0;i<(int)AdjList[v].size();i++){
					
						int vertex=AdjList[v][i];
						if(dist[vertex]==inf){
							dist[vertex]=dist[v]+1;
							if(dist[vertex]>ttl){found=true;dist[vertex]=inf;break;}
							
							q.push(vertex);
						}
					
				}
				if(found){break;}
			}
			//mengosongkan q seandainya udah ke break dulu
			while(!q.empty()){q.pop();}
			/*printf("listnode yang inf:");
			for(i=0;i<listnode.size();i++){if(dist[listnode[i]]==inf) printf(" %d", listnode[i]);}
			printf("\n");*/
			for(i=0;i<listnode.size();i++){if(dist[listnode[i]]==inf) cnt++;}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc++,cnt,awal,ttl);
		}
		
		AdjList.clear();
		listnode.clear();
		mapper.clear();
	}
	return 0;
}