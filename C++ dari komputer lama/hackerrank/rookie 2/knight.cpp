#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> ii;
#define inf 1000000000
int mat[26][26];
int dist[26][26],n;
void inisialisasi(){
	int k,l;
	for(k=1;k<=n;k++){
		for(l=1;l<=n;l++){
			dist[k][l]=inf;
		}
	}
}
queue <ii> q;
int main(){
	int i,j,k,r,c,r_new,c_new;
	scanf("%d",&n);
	//inisialisasi dist
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			inisialisasi();
			dist[1][1]=0;
			r = i; c = j;
			q.push(ii(1,1));
			int dr[]={-1*r,-1*c,-1*c,-1*r,r,c,c,r};
			int dc[]={-1*c,-1*r,r,c,-1*c,-1*r,r,c};
			/*printf("list perpindahan:\n");
			for(k=0;k<=7;k++){printf("%d %d\n",dr[k],dc[k]);}*/
			while(!q.empty()){
				ii data = q.front(); q.pop();
				for(k=0;k<=7;k++){
					r_new = data.first+dr[k]; c_new = data.second+dc[k];
					if(r_new >=1 && r_new <=n && c_new >=1 && c_new <=n){
						if(dist[r_new][c_new]==inf){
							dist[r_new][c_new]=dist[data.first][data.second]+1;
							q.push(ii(r_new,c_new));
							//printf("yang dipush: %d %d\n",r_new,c_new);	
						}
						
					}
				}	
			}
			if(j==1){
				if(dist[n][n]==inf){printf("-1");}
				else{printf("%d",dist[n][n]);}
			}else{
				if(dist[n][n]==inf){printf(" -1");}
				else{printf(" %d",dist[n][n]);}
			}
		}
		printf("\n");
	}
	return 0;
}