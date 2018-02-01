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

int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,2,1,-1,-2};
int rajax[]={-1,-1,0,1,1,1,0,-1};
int rajay[]={0,1,1,1,0,-1,-1,-1};
int dist[110][110];

int main(){
	int tc,i,j,k,r,c;
	string kata[110];
	scanf("%d",&tc);
	while(tc--){
		vii listKuda;
		ii posA, posB;
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){cin>>kata[i];}
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				dist[i][j] = inf;
				if(kata[i][j]=='Z'){
					//printf("yang dipush: %d %d\n",i,j);
					listKuda.pb(ii(i,j));
				}else if(kata[i][j]=='A'){
					posA = ii(i,j);
				}else if(kata[i][j]=='B'){
					posB = ii(i,j);
				}
			}
		}
		//tandain yg disekeliling Z
		int ukuran = listKuda.size();
		for(i=0;i<ukuran;i++){
			ii front = listKuda[i];
			int x = front.first, y = front.second;
			for(j=0;j<8;j++){
				int xbaru = x+dx[j], ybaru = y+dy[j];
				if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
					if(kata[xbaru][ybaru]=='.'){
						//printf("yang dijadikan Z: %d %d\n",xbaru,ybaru);
						kata[xbaru][ybaru] = 'Z';
					}
				}
			}
		}
		/*printf("peta:\n");
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				printf("%c",kata[i][j]);
			}
			printf("\n");
		}*/
		//bfs dari A

		queue<ii> q; q.push(posA);
		dist[posA.first][posA.second] = 0;
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int x = front.first, y = front.second;
			for(i=0;i<8;i++){
				int xbaru = x+rajax[i], ybaru = y+rajay[i];
				if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
					if((kata[xbaru][ybaru]=='.' || kata[xbaru][ybaru]=='B') && dist[xbaru][ybaru]==inf){
						dist[xbaru][ybaru] = dist[x][y] + 1;
						//printf("dist[%d][%d]: %d\n",xbaru,ybaru,dist[xbaru][ybaru]);
						q.push(ii(xbaru,ybaru));
					}
				}
			}
		}
		int absis = posB.first, ordinat = posB.second;

		if(dist[absis][ordinat]==inf){
			printf("King Peter, you can't go now!\n");
		}else{
			printf("Minimal possible length of a trip is %d\n",dist[absis][ordinat]);
		}
	}
	return 0;
};