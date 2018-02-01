#include <bits/stdc++.h>

using namespace std;
#define maxvertex 100
#define visited 1
#define unvisited -1
typedef pair<int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;


vector <vi> AdjList;

int main(){
	ios_base::sync_with_stdio(false);
	char kata[60];
	char kata1[60],kata2[60];
	queue <int> q;
	char line[80];
	map <string,int> mapper;
	map <int,string> mapper2;
	map <string,int>::iterator it;
	map <int,string>::iterator it2;
	int V,i,tc,E,v,v2,cnt,a,b,j;
	int indegree[110],dfs_num[110];
	vi sorted;
	tc=1;
	while(scanf("%d",&V)!=EOF){
		AdjList.clear();
		memset(dfs_num,unvisited,sizeof dfs_num);
		memset(indegree,0,sizeof indegree);
		printf("Case #%d: Dilbert should drink beverages in this order:",tc++);
		//scanf("%d",&V);
		//cnt=0;
		AdjList.assign(V,vi());
		for(i=0;i<V;i++){
			scanf("%s",kata);
			mapper[(string)kata]=i;
			mapper2[i]=(string)kata;
		}

		/*for(it=mapper.begin();it!=mapper.end();++it){
			cout<<((string)it->first).c_str()<< " "<<it->second<<endl;
		}*/

		scanf("%d",&E);
		for(i=0;i<E;i++){
			scanf("%s %s",kata1,kata2);
			it=mapper.find(kata1);a=it->second;
			it=mapper.find(kata2);b=it->second;
			//printf("kata1 %s indeks %d kata2 %s indeks %d\n",kata1,a,kata2,b);
			indegree[b]++;
			AdjList[a].push_back(b);
		}
		//bool done=false;
		
			//done=true;
			for(i=0;i<V;i++){
				if(indegree[i]==0 && dfs_num[i]==unvisited){
					//done=false;
					dfs_num[i]=visited;
					printf(" %s",mapper2[i].data());
					for(j=0;j<(int)AdjList[i].size();j++){
						int vertex;
						vertex=AdjList[i][j];
						indegree[vertex]--;
					}
					i=-1;
				}
				
			}
		
		
		printf(".\n\n");
		
		sorted.clear();
		mapper.clear();
		mapper2.clear();
		AdjList.clear();
	}
	return 0;
}