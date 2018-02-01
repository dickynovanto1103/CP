#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef pair<int,int> ii;

int dist[3005][3005];

int main(){
	int n,m,i,j;
	ii idxS,idxP;
	string kata[3050];
	queue<ii> q;
	int x[4] = {-1,0,1,0};
	int y[4] = {0,1,0,-1};
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			dist[i][j] = inf;
		}
	}
	for(i=0;i<n;i++){cin>>kata[i];}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j]=='S'){idxS = ii(i,j);}
			else if(kata[i][j]=='F'){idxP = ii(i,j);}
		}
	}
	int r = idxS.first, c = idxS.second;
	//printf("tinjau s: r: %d c: %d\n",r,c);
	dist[r][c] = 0; q.push(ii(r,c));
	while(!q.empty()){
		ii temp = q.front(); q.pop();
		r = temp.first; c = temp.second;
		//printf("meninjau r: %d c: %d\n",r,c);
		for(i=0;i<4;i++){
			int a = r+x[i], b = c+y[i];
			if(a>=0 && a<n && b>=0 && b<m){
				if(kata[a][b]!='*'){
					if(dist[a][b]==inf){
						dist[a][b] = dist[r][c] + 1;
						//printf("dist[%d][%d] jd: %d\n",a,b,dist[a][b]);
						q.push(ii(a,b));
					}
				}
			}
		}
	}
	r = idxP.first, c = idxP.second;
	//printf("tinjau P: r: %d c: %d\n",r,c);
	if(dist[r][c]==inf){
		printf("-1\n");
	}else{
		printf("%d\n",dist[r][c]);
	}
	return 0;
}