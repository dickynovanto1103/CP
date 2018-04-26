#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;

char kata[maxn][maxn];
int n,m;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int dist[maxn][maxn];
bool isValid(int x, int y){
	return (x>=0 && x<n && y>=0 && y<m);
}
queue<ii> q;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	ii koordinatY[4];
	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){scanf("%s",kata[i]);}
		int cnt = 0;
		ii koorBawang;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				dist[i][j] = inf;
				if(kata[i][j] == 'Y'){koordinatY[cnt] = ii(i,j); cnt++;}
				else if(kata[i][j] == 'O'){koorBawang = ii(i,j);}
			}
		}
		for(i=0;i<4;i++){
			int x = koordinatY[i].first, y = koordinatY[i].second;
			dist[x][y] = 0;
			q.push(koordinatY[i]);
		}
		int ans = inf;
		printf("\n\ntest baru\n\n");
		while(!q.empty()) {
			//ambil 4;
			for(i=0;i<4;i++){
				koordinatY[i] = q.front(); q.pop();
				printf("pop ke %d : %d %d\n",i,koordinatY[i].first,koordinatY[i].second);
			}
			if(q.empty()){
				printf("queue skrg kosong\n");
			}
			for(i=0;i<8;i++){
				bool adaNabrak = false, sudahTerkunjungiSemua = true, semuaValid = true;
				for(j=0;j<4;j++){
					int x = koordinatY[j].first, y = koordinatY[j].second;

					int xbaru = x + dx[i], ybaru = y + dy[i];
					if(isValid(xbaru,ybaru)){
						printf("x: %d y: %d xbaru: %d ybaru: %d\n",x,y,xbaru,ybaru);
						if(kata[xbaru][ybaru] == '#'){adaNabrak = true; break;}
						if(dist[xbaru][ybaru] == inf){sudahTerkunjungiSemua = false;}	
					}else{
						semuaValid = false;
					}
					
				}
				if(!semuaValid){printf("ada yg out of range\n"); continue;}
				if(adaNabrak){printf("ada yang nabrak\n"); continue;}
				if(sudahTerkunjungiSemua){printf("sudahTerkunjungiSemua\n"); continue;}
				// printf("adaNabrak: %d\n",adaNabrak);
				// printf("sudahTerkunjungiSemua: %d\n",sudahTerkunjungiSemua);
				if(!adaNabrak){
					if(sudahTerkunjungiSemua){continue;}
					for(j=0;j<4;j++){
						int x = koordinatY[j].first, y = koordinatY[j].second;
						int xbaru = x + dx[i], ybaru = y + dy[i];
						if(isValid(xbaru,ybaru)) {
							dist[xbaru][ybaru] = (dist[x][y] + 1);
							printf("dist[%d][%d] jadi :%d\n",xbaru,ybaru,dist[xbaru][ybaru]);
							if(kata[xbaru][ybaru] == 'O'){ans = min(ans, dist[xbaru][ybaru]);}
							q.push(ii(xbaru,ybaru));	
							// printf("yang dipush: %d %d\n",xbaru, ybaru);
						}
						
					}	
				}
			}
		}
		if(ans == inf){
			printf("-1\n");
		}else{
			printf("%d\n",ans);	
		}
		
	}
	return 0;
};