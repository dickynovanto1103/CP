#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dist[755][755];

int main() {
	int tc,i,j,r,c,n;
	scanf("%d",&tc);
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};

	while(tc--){
		scanf("%d %d %d",&r,&c,&n);
		//printf("n: %d\n",n);
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				dist[i][j] = inf;
			}
		}
		while(n--){
			int u,v,w;

			scanf("%d %d %d",&u,&v,&w);
			/*printf("i: %d\n",i);
			printf("u: %d v: %d w: %d\n",u,v,w);*/
			int brsAwal = max(1,u-w+1), brsAkhir = min(r,u+w-1), kolomAwal = max(1,v-w+1), kolomAkhir = min(c,v+w-1);
			//printf("brsAwal: %d brsAkhir: %d kolom awal: %d kolomAkhir: %d\n",brsAwal, brsAkhir, kolomAwal, kolomAkhir);
			for(i=brsAwal;i<=brsAkhir;i++){
				if(i==brsAwal || i==brsAkhir){
					for(j=kolomAwal;j<=kolomAkhir;j++){
						//printf("i: %d j: %d\n",i,j);
						int jarak = abs(i-u) + abs(j-v);
						if(jarak<w){dist[i][j] = -inf;}
					}	
				}else{
					j = kolomAwal;
					//printf("kolom awal: %d\n",kolomAwal);
					//awal
					int jarak = abs(i-u) + abs(j-v);
					while(jarak>=w){j++; jarak = abs(i-u) + abs(j-v);}
					//printf("yang dibikin inf i: %d j: %d\n",i,j);
					dist[i][j] = -inf;
					//akhir
					j = kolomAkhir;
					//printf("kolom akhir: %d\n",kolomAkhir);
					jarak = abs(i-u) + abs(j-v);
					while(jarak>=w){j--; jarak = abs(i-u) + abs(j-v);}
					//printf("yang dibikin inf i: %d j: %d\n",i,j);
					dist[i][j] = -inf;
				}
				
			}
		}
		int x1,y1,x2,y2;
		/*printf("peta\n");
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				if(dist[i][j]==inf){printf("0");}
				else{printf("1");}
			}
			printf("\n");
		}*/

		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		queue<ii> q; q.push(ii(x1,y1));
		dist[x1][y1] = 0;
		bool found = false;
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int x = front.first, y = front.second;
			for(i=0;i<4;i++){
				int xbaru = x+dx[i], ybaru = y+dy[i];
				if(xbaru>=1 && xbaru<=r && ybaru>=1 && ybaru<=c){
					if(dist[xbaru][ybaru]==inf){
						dist[xbaru][ybaru] = dist[x][y] + 1;
						if(xbaru==x2 && ybaru==y2){found = true; break;}
						q.push(ii(xbaru,ybaru));
					}
				}
			}
			if(found){break;}

		}
		if((dist[x2][y2]==inf)){printf("-1\n");}
		else{printf("%d\n", dist[x2][y2]);}

	}
	return 0;
}