#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int dist[1000][1000];
int a[1000][1000];

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

int main(){
	int tc,r,c,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&r,&c);
		//inisialisasi dist
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				dist[i][j]=inf;
			}
		}

		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%d",&a[i][j]);
			}
		}
		dist[0][0]=a[0][0];
		priority_queue <iii,vector <iii>,greater <iii> > pq; pq.push(make_pair(dist[0][0],ii(0,0)));
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			int d = front.first, x = front.second.first, y = front.second.second;
			if(d > dist[x][y]) continue;
			for(i=0;i<=3;i++){
				int xbaru = x+dr[i], ybaru=y+dc[i];
				if(xbaru>=0 && xbaru <r && ybaru>=0 && ybaru <c){
					if(a[xbaru][ybaru]+dist[x][y] < dist[xbaru][ybaru]){
						dist[xbaru][ybaru] = a[xbaru][ybaru]+dist[x][y];
						pq.push(make_pair(dist[xbaru][ybaru],ii(xbaru,ybaru)));
					}	
				}
				
			}
		}
		printf("%d\n",dist[r-1][c-1]);
	}
	return 0;
}