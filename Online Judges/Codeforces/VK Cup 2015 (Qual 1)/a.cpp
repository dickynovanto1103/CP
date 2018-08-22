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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

bool isVisited[401];
int jawab;

void dfs(int node, int height){
	isVisited[node] = true;
	// printf("halo\n");
	jawab = max(jawab, height);
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]){
			dfs(v,height+1);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	map<string, int> mapper;
	AdjList.assign(401,vi());
	memset(isVisited, false, sizeof isVisited);
	mapper["polycarp"] = 0;
	int cnt = 1;
	for(i=0;i<n;i++){
		string nama1,nama2,dum;
		cin>>nama1>>dum>>nama2;
		for(j=0;j<nama1.length();j++){
			nama1[j] = tolower(nama1[j]);
		}
		for(j=0;j<nama2.length();j++){
			nama2[j] = tolower(nama2[j]);
		}
		int idx1, idx2;
		if(mapper.find(nama1) == mapper.end()){
			mapper[nama1] = cnt;
			idx1 = cnt;
			cnt++;
		}else{
			idx1 = mapper[nama1];
		}
		if(mapper.find(nama2) == mapper.end()){
			mapper[nama2] = cnt;
			idx2 = cnt;
			cnt++;
		}else{
			idx2 = mapper[nama2];
		}
		// AdjList[idx1].pb(idx2);
		AdjList[idx2].pb(idx1);
	}
	int ans = 0;
	dfs(0,1);
	printf("%d\n",jawab);
	return 0;
};