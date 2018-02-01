#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
#define inf 1000000000
typedef pair <int,int> ii;
typedef pair <ii,int> iii;
int dist[30][30][30];
int dr[]={-1,1,0,0,0,0};
int dc[]={0,0,-1,1,0,0};
int dh[]={0,0,0,0,-1,1};
string kata[30][30];
int main(){
	int L,r,c,i,j,k,a1,b1,c1,a2,b2,c2,akhir1,akhir2,akhir3;
	queue <iii> q;
	while(scanf("%d %d %d",&L,&r,&c),(L||r||c)){
		for(i=0;i<L;i++){
			for(j=0;j<r;j++){
				for(k=0;k<c;k++){dist[i][j][k]=inf;}
			}
		}
		for(i=0;i<L;i++){
			for(j=0;j<r;j++){
				cin>>kata[i][j];
			}
		}
		/*for(i=0;i<L;i++){
			for(j=0;j<r;j++){
				for(k=0;k<c;k++){printf("%c",kata[i][j][k]);}
				printf("\n");
			}
			cout<<"\n";
		}*/
		for(i=0;i<L;i++){
			for(j=0;j<r;j++){
				for(k=0;k<c;k++){
					if(kata[i][j][k]=='S'){a1 = i; b1 = j; c1 = k;}
					else if(kata[i][j][k]=='E'){a2 = i; b2 = j; c2 = k;}
				}
			}
		}
		/*printf("a1: %d b1: %d c1: %d\n",a1,b1,c1);
		printf("a2: %d b2: %d c2: %d\n",a2,b2,c2);*/
		akhir1 = a2; akhir2 = b2; akhir3 = c2;
		dist[a1][b1][c1]=0; q.push(make_pair(ii(a1,b1),c1));
		int counting=1;
		while(!q.empty()){
			//printf("%d\n",counting++);
			iii front = q.front(); q.pop();
			a1 = front.first.first; b1 = front.first.second; c1 = front.second;
			for(i=0;i<6;i++){
				a2 = a1 + dr[i]; b2 = b1 + dc[i]; c2 = c1 + dh[i];
				if(a2>=0 && a2<L && b2>=0 && b2<r && c2>=0 && c2<c){
					if((kata[a2][b2][c2]=='.' || kata[a2][b2][c2]=='E') && dist[a2][b2][c2]==inf){
						dist[a2][b2][c2]=dist[a1][b1][c1] + 1;
						//printf("dist[%d][%d][%d] = %d\n",a2,b2,c2,dist[a2][b2][c2]);
						q.push(make_pair(ii(a2,b2),c2));
					}
					
				}
			}
		}
		if(dist[akhir1][akhir2][akhir3]==inf){printf("Trapped!\n");}
		else{printf("Escaped in %d minute(s).\n",dist[akhir1][akhir2][akhir3]);}
	}
	return 0;
}
