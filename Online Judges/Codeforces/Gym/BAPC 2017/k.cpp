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

const int maxn = 1e3 + 3;

string kata[maxn];

vector<vi> AdjList;
vi ans;
bool isVisited[maxn];

void dfs(int node){
	isVisited[node] = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]){
			dfs(v);
		}
	}
	ans.pb(node);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>kata[i];
	}

	bool tabelChar[3];
	
	AdjList.assign(n+1,vi());
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			// printf("i: %d j: %d\n",i,j);
			char kar = kata[i][j];
			if(kar == '1'){
				AdjList[i].pb(j);
			}else if(kar == 'X'){break;}
			else{
				AdjList[j].pb(i);
			}
		}
	}
	memset(isVisited, false, sizeof isVisited);
	dfs(0);
	if(ans.size() != n){
		printf("impossible\n");
	}else{
		for(i=0;i<ans.size();i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}

	return 0;
};