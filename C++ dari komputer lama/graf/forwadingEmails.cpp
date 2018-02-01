#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector<int> vi;
typedef pair <int,int> ii;

vector <vi> AdjList;
vi dfs_num;
int cnt;

void dfs(int a){
	int i;
	dfs_num[a]=visited;
	cnt++;
	for(i=0;i<AdjList[a].size();i++){
		int v = AdjList[a][i];
		if(dfs_num[v]==unvisited){dfs(v);}
	}
}

int main(){
	int tc,i,j,V,maks,test=1,idx;
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&V);
		AdjList.assign(V+1,vi());
		int a,b;
		
		for(i=0;i<V;i++){
			scanf("%d %d",&a,&b);
			AdjList[a].push_back(b);
		}
		maks = -1;
		for(i=1;i<=V;i++){
			//dfs dari node i;

			dfs_num.assign(V+1,unvisited); // inisialisasi dulu dengan unvisited
			cnt=0;
			dfs(i);
			if(maks < cnt){maks = cnt; idx = i;}
			
			printf("untuk node: %d cnt: %d\n",i,cnt);
		}
		printf("Case %d: %d\n",test++,idx);


		AdjList.clear();
	}
	return 0;
}