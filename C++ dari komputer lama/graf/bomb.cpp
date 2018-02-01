#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define visited 1
#define unvisited -1
typedef pair<int,int> ii;
typedef vector <int> vi;

int a[1005][1005];

int main(){
	int r,c,i,j,k,n,row,column,banyaktiaprow,rsource,csource,rdes,cdes;
	int dr[]={0,1,0,-1};
	int dc[]={1,0,-1,0};
	queue <ii> q;
	ii grid;
	vi dist,dfs_num;

	while(scanf("%d %d",&r,&c),(r || c)){
		dist.assign(r*c+10,inf);
		dfs_num.assign(r*c+10,unvisited);
		for(i=0;i<r;i++){
			for(j=0;j<r;j++){
				a[i][j]=1;//inisialisasi
			}
		}
		scanf("%d",&n);
		while(n--){
			scanf("%d %d",&row,&banyaktiaprow);
			for(i=1;i<=banyaktiaprow;i++){scanf("%d",&column); a[row][column]=inf;}
		}
		scanf("%d %d %d %d",&rsource,&csource,&rdes,&cdes);
		q.push(ii(rsource,csource)); 
		dist[rsource*c+csource]=0;//untuk idx tiap cell grid
		dfs_num[rsource*c+csource]=visited;
		
		while(!q.empty()){
			//printf("test %d\n",i++);
			grid=q.front(); q.pop();
			for(i=0;i<4;i++){
				int x,y;
				x=grid.first+dr[i]; y=grid.second+dc[i];
				if(a[x][y]==inf || x < 0 || x>=r || y < 0 || y>=c || dfs_num[x*c+y]==visited){continue;}
				else{q.push(ii(x,y)); dist[x*c+y]=min(dist[x*c+y],dist[grid.first*c+grid.second]+1); dfs_num[x*c+y]=visited;}
			}
		}
		printf("%d\n",dist[rdes*c+cdes]);
		dist.clear();
	}
	return 0;
}