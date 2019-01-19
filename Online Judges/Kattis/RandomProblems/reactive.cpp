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

vector<vi> AdjList;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(maxn, vi());
	int indegree[maxn];
	memset(indegree, 0, sizeof indegree);

	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
		indegree[b]++;
	}

	queue<int> q;
	for(i=0;i<n;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	vi ans;

	while(!q.empty()){
		if(q.size() > 1){printf("back to the lab\n"); return 0;}
		int front = q.front(); q.pop();
		ans.pb(front);
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			indegree[v]--;
			if(indegree[v] == 0){
				q.push(v);
			}
		}
	}

	for(i=0;i<ans.size();i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");

	return 0;
};