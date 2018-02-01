#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef pair<int,int> ii;

bool isInsideCircle(int x1, int y1, int x2, int y2, int r) {
	int dx = x1 - x2, dy = y1-y2;
	int euc = dx*dx + dy*dy, rsq = r*r;
	return euc<=rsq ? true : false;
}

int main(){
	int r,c,i,j,k;
	int n,m;
	int x[4] = {-1,0,1,0};
	int y[4] = {0,1,0,-1};
	int dist[205][205];
	while(scanf("%d %d",&r,&c), (r||c)){
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){dist[i][j]=inf;}
		}
		scanf("%d",&m);
		int bil1,bil2;
		for(i=0;i<m;i++){scanf("%d %d",&bil1,&bil2); dist[bil1][bil2] = -1;}
		scanf("%d",&n);
		int radius;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&bil1,&bil2,&radius);
			int awalbaris = max(1,bil1-radius), akhirbaris = min(r,bil1+radius), awalkolom = max(1,bil2-radius), akhirkolom = min(c,bil2+radius);
			for(j=awalbaris;j<=akhirbaris;j++){
				for(k=awalkolom;k<=akhirkolom;k++){
					if(isInsideCircle(j,k,bil1,bil2,radius)){dist[j][k]=-1;}
				}
			}
			//dist[awalbaris][awalkolom] = inf; dist[awalbaris][awalkolom] = inf; dist[awalbaris][awalkolom] = inf; dist[awalbaris][awalkolom] = inf;
		}
		//bfs dari 0,0;
		queue<ii> q;
		dist[1][1] = 0; q.push(ii(1,1));
		while(!q.empty()){
			ii front = q.front(); q.pop();
			for(i=0;i<4;i++){
				int rbaru = front.first + x[i], cbaru = front.second + y[i];
				if(rbaru>=1 && rbaru<=r && cbaru>=1 && cbaru<=c){
					if(dist[rbaru][cbaru]!=-1 && dist[rbaru][cbaru]==inf){

						dist[rbaru][cbaru] = dist[front.first][front.second] + 1;
						//printf("yang dipush %d %d dengan dist baru: %d\n",rbaru,cbaru, dist[rbaru][cbaru]);
						q.push(ii(rbaru,cbaru));
					}
				}
			}
		}
		if(dist[r][c]==inf){printf("Impossible.\n");}
		else{printf("%d\n",dist[r][c]);}
	}
	
	return 0;
}