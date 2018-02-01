#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dfs_num;
double ans[100010];
int cnt = 0;
int sum = 0;

double dfs(int a){
	dfs_num[a] = visited;
	int i;
	//printf("a: %d depth: %d counter: %d\n",a,depth,counter);

	double sum = 0;
	int counter = 0;
	for(i=0;i<AdjList[a].size();i++){
		int v = AdjList[a][i];
		if(dfs_num[v]==unvisited){
			sum += (dfs(v) + 1);
			counter++;
		}
	}
	//printf("counter: %d a: %d sum: %lf\n",counter,a,sum);
	if(counter==0){return ans[a] = 0;}
	else{return ans[a] = sum/(double)counter;}
}

int main() {
	int n,a,b,i;
	scanf("%d",&n);
	memset(ans,-1,sizeof ans);
	AdjList.assign(n+1,vi()); dfs_num.assign(n+1,unvisited);
	for(i=0;i<n-1;i++){scanf("%d %d",&a,&b); AdjList[a].pb(b); AdjList[b].pb(a);}
	dfs(1);
	printf("%.15lf\n",ans[1]);
	return 0;
}