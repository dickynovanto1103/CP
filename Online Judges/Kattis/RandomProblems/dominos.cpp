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

const int maxn = 1e5 + 5;

vi sortedList;

vector<vi> depan;
bool isVisited[maxn];
int comp[maxn];

void dfs1(int n){
	isVisited[n] = true;
	for(int i=0;i<depan[n].size();i++){
		int v = depan[n][i];
		if(!isVisited[v]){dfs1(v);}
	}
	sortedList.pb(n);
}

void dfs2(int n, int c){
	isVisited[n] = false;
	comp[n] = c;
	for(int i=0;i<depan[n].size();i++){
		int v = depan[n][i];
		if(isVisited[v]){dfs2(v, c);}
	}
}

int main(){
	int n,m,i,j;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		depan.assign(n+1,vi());
		sortedList.clear();
		int indegree[maxn];
		memset(indegree, 0, sizeof indegree);
		memset(isVisited, false, sizeof isVisited);
		memset(comp, 0, sizeof comp);

		for(i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			depan[a].pb(b);
		}

		for(i=1;i<=n;i++){
			if(!isVisited[i]){dfs1(i);}
		}

		for(i=0;i<sortedList.size();i++){
			printf("sortedList[%d]: %d\n",i,sortedList[i]);
		}

		int c = 0;
		for(i=0;i<sortedList.size();i++){
			int bil = sortedList[i];
			if(isVisited[bil]){dfs2(bil, ++c);}
		}

		for(i=1;i<=n;i++){
			printf("comp[%d]: %d\n",i,comp[i]);
		}

		for(i=1;i<=n;i++){
			for(j=0;j<depan[i].size();j++){
				if(comp[i] != comp[depan[i][j]]){
					indegree[comp[depan[i][j]]]++;
				}
			}
		}
		int cnt = 0;
		for(i=1;i<=c;i++){
			if(indegree[i] == 0){

				cnt++;
			}
		}
		printf("%d\n",cnt);	
	}
	

	return 0;
};