#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector <int> vi;
typedef long long ll;

vector <vi> AdjList;
vi bfs_num;
int main(){
	int n,q,i,j,a[1005],bil,u,v;
	queue <int> que;
	ll ans;
	scanf("%d",&n);
	bfs_num.assign(n+5,unvisited);
	AdjList.assign(n+5,vi());
	for(i=1;i<=n;i++){scanf("%d",&bil); a[i]=bil;}

	for(i=0;i<n-1;i++){scanf("%d %d",&u,&v);AdjList[u].push_back(v); AdjList[v].push_back(u);}
	for(i=1;i<=n;i++){
		printf("node %d:",i);
		for(j=0;j<AdjList[i].size();j++){
			int temp = AdjList[i][j];
			printf(" %d(%d)",temp,a[temp]);
		}
		printf("\n");
	}
	scanf("%d",&q);
	while(q--){
		ans=0;
		scanf("%d %d",&u,&v);
		if(a[u]==v){ans=1;}
		que.push(u); bfs_num[u]=visited;
			//printf("ans: %lld\ntetangga dr %d:",ans,u);
		while(!que.empty()){
			int front = que.front(); que.pop();
			for(i=0;i<AdjList[front].size();i++){
				int temp = AdjList[front][i];
				//printf(" %d",temp);

				if(a[temp]==v && bfs_num[temp]==unvisited){ans++;que.push(temp); bfs_num[temp]=visited;}
				
				//printf("\n ans: %lld\n",ans);
			}		
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}