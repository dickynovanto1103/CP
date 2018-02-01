#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef pair<char,char> cc;
typedef pair<int,int> ii;
typedef vector<int> vi;
string listkata[1000010];
vi dfs_num;
vector<vi> AdjList;

void dfs(int u){
	dfs_num[u] = visited;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v]==unvisited){dfs(v);}
	}
}

int main(){
	int tc, cnt,i,j;
	map<char,int> mapper;
	scanf("%d",&tc);
	while(tc--){
		string kata;
		cnt=0;
		AdjList.assign(27,vi());
		while(cin>>kata && kata[0]!='*'){listkata[cnt]=kata; cnt++;}
		cin>>kata;
		int n = cnt;
		cnt=0;
		for(i=0;i<kata.length();i+=2){
			char kar = kata[i];
			mapper[kar] = cnt++;
		}
		//printf("n: %d\n",n);
		AdjList.clear();
		for(i=0;i<n;i++){
			kata = listkata[i];
			int a = mapper[kata[1]], b = mapper[kata[3]];
			//printf("a: %d, b: %d\n",a,b);
			AdjList[a].push_back(b); 
			AdjList[b].push_back(a);
		}
		dfs_num.assign(cnt,unvisited);
		/*for(i=0;i<cnt;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){
				printf(" %d",AdjList[i][j]);
			}
			printf("\n");
		}*/
		int cntTree = 0, cntAcorn = 0;
		for(i=0;i<cnt;i++){
			if(dfs_num[i]==unvisited){
				dfs(i);
				//if(i==3){printf("masuk sini\n");}
				if(AdjList[i].size()==0){cntAcorn++;}
				else{cntTree++;}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n",cntTree,cntAcorn);
		AdjList.clear(); dfs_num.clear(); mapper.clear();
	}
	return 0;
}