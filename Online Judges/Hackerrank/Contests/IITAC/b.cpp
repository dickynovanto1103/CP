#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
#define explored 2
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> AdjList;
vi dfs_num;
vi ans;
bool foundCycle;

void toposort(int u){
	int i;
	dfs_num[u] = visited;
	
	for(i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
	
		if(dfs_num[v]==unvisited){
			toposort(v);
		}
	}
	ans.push_back(u);
}

void graphCheck(int u){
	if(foundCycle){return;}
	dfs_num[u] = explored;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == unvisited){
			graphCheck(v);
		}
		if(dfs_num[v] == explored){
			foundCycle = true;
		}
	}
	dfs_num[u] = visited;
}

int main(){
	int n,i,j;
	map<string,int> mapper;
	map<string,int>::iterator it;
	map<int,string> mapper2;
	string kata1,kata2,kata;
	scanf("%d",&n);
	int cnt = 0;
	dfs_num.assign(20000,unvisited); AdjList.assign(20000,vi());

	while(n--){
		cin>>kata1;
		cin>>kata; cin>>kata; cin>>kata;
		cin>>kata2;
		it =mapper.find(kata1);
		if(it==mapper.end()){mapper[kata1] = cnt++;}
		it =mapper.find(kata2);
		if(it==mapper.end()){mapper[kata2] = cnt++;}
		int a = mapper[kata1], b = mapper[kata2];
		mapper2[a] = kata1; mapper2[b] = kata2;
		AdjList[a].push_back(b);
	}
	//cek ada cycle atau ga
	foundCycle = false;	
	for(i=0;i<cnt;i++){
		if(dfs_num[i]==unvisited){graphCheck(i);}
		if(foundCycle) break;
	}
	if(foundCycle){printf("Tidak Mungkin\n");}
	else{
		//iterasi lagi buat nentuin toposortnya
		dfs_num.assign(cnt, unvisited);
		for(i=0;i<cnt;i++){
			if(dfs_num[i]==unvisited){toposort(i);}
		}
		reverse(ans.begin(),ans.end());
		
		for(i=0;i<ans.size();i++){
			int idx = ans[i];
			cout<<mapper2[idx]<<endl;
		}
	}

	return 0;
}