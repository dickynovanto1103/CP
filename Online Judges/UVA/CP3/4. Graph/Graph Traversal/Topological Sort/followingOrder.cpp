#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector<int> vi;

vector<vi> AdjList;
vector<string> anslist;
vi dfs_num;
int cnt;
map<char,int> mapper;
map<char,int>::iterator it;
map<int,char> mapper2;
map<int,char>::iterator it2;

//bool foundans;
void allTopo(int indegree[], int V, vi ans, vi dfs_num1){
	int i;
	if(ans.size()==V){
		string kata = "";
		//printf("pernah masuk sini\n");
		for(i=0;i<ans.size();i++){
			int idx = ans[i];
			kata+=mapper2[idx];
			//printf("%c",);
		}
		anslist.push_back(kata);
		//printf("\n");
	}else{
		//cek semua node
		for(i=0;i<V;i++){
			if(indegree[i]==0 && dfs_num1[i]==unvisited){
				ans.push_back(i);
				//printf("yang dipush: %d\n",i);
				dfs_num1[i] = visited;
				for(int j=0;j<AdjList[i].size();j++){
					int v = AdjList[i][j];
					indegree[v]--;
				}
				allTopo(indegree,V,ans,dfs_num1);
				ans.pop_back();
				dfs_num1[i] = unvisited;
				for(int j=0;j<AdjList[i].size();j++){
					int v = AdjList[i][j];
					indegree[v]++;
				}
			}

		}
	}
}
int main(){
	string kata1, kata2;
	int i,test=0;
	
	while(getline(cin,kata1)){
		if(test==1){printf("\n");}
		getline(cin,kata2);
		//mendapatkan variabel
		int ukuran1 = kata1.length(), ukuran2 = kata2.length();
		cnt = 0;
		for(i=0;i<ukuran1;i++){
			if(kata1[i]!=' '){char kar = kata1[i]; mapper[kar]=cnt; mapper2[cnt]=kar; cnt++;}
		}
		AdjList.assign(cnt,vi());
		int indegree[cnt];
		memset(indegree,0,sizeof indegree);
		for(i=0;i<ukuran2;i+=4){
			int a = mapper[kata2[i]];
			int b = mapper[kata2[i+2]];
			char kar1 = kata2[i];
			char kar2 = kata2[i+2];
			//printf("%c ke %c\n",kar1,kar2);
			AdjList[a].push_back(b); indegree[b]++;
		}
		vi ans;
		dfs_num.assign(cnt,unvisited);
		allTopo(indegree,cnt,ans,dfs_num);
		sort(anslist.begin(), anslist.end());
		for(i=0;i<anslist.size();i++){
			cout<<anslist[i]<<endl;
		}
		mapper.clear(); mapper2.clear(); AdjList.clear(); dfs_num.clear(); anslist.clear();
		test=1;
	}
	return 0;
}