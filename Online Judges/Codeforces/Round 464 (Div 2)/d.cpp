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

bool isVisited[256];
vii listPair;

void dfs(int n){
	isVisited[n] = true;
	int i,j;
	for(i=0;i<AdjList[n].size();i++){
		char v = AdjList[n][i];
		if(!isVisited[v]){
			listPair.pb(ii(n,v));
			dfs(v);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(256,vi());
	string kata1,kata2;
	cin>>kata1>>kata2;
	// printf("test\n");
	for(i=0;i<n;i++){
		char kar1 = kata1[i];
		char kar2 = kata2[i];
		AdjList[kar1].pb(kar2);
		AdjList[kar2].pb(kar1);
	}
	memset(isVisited,false,sizeof isVisited);
	
	for(i=97;i<=122;i++){
		if(!isVisited[i]){
			dfs(i);
		}
	}

	printf("%d\n",(int)listPair.size());
	for(i=0;i<listPair.size();i++){
		printf("%c %c\n",listPair[i].first,listPair[i].second);
	}
	return 0;
};