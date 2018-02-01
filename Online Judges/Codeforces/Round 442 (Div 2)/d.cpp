#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000LL
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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

string kata[1010];
ll dist[1001][1001][4];
queue<iii> q;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	int n,m,k;
	int i,j;
	
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){cin>>kata[i];}
	int x1,y1,x2,y2;
	//printf("n: %d m: %d k: %d\n",n,m,k);
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	x1--;y1--; x2--;y2--;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			for(int l=0;l<4;l++){
				dist[i][j][l] = inf;	
			}
		}
	}
	//if(x1==x2 && y1==y2){printf("0\n"); return 0;}
	dist[x1][y1][0] =  0;
	q.push(mp(ii(x1,y1),0));
	while(!q.empty()){
		iii front = q.front(); q.pop();
		int x = front.first.first, y = front.first.second, dir = front.second;
		for(i=0;i<4;i++){
			for(j=1;j<=k;j++){
				//printf("j: %d k :%d\n",j,k);
				int xbaru = x+(dx[i]*j), ybaru = y+(dy[i]*j);
				
				if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
					if(kata[xbaru][ybaru]=='#'){break;}
					if(dist[xbaru][ybaru][i]==inf && kata[xbaru][ybaru]=='.'){
						dist[xbaru][ybaru][i] = 1+dist[x][y][dir];
						q.push(mp(ii(xbaru,ybaru),i));
					}else{
						break; //di "tetangganya" udah dikunjungi..keluar aja buat pruning
					}
				}else{
					break;
				}
			}
			
		}
	}
	ll ans = inf;
	for(i=0;i<4;i++){ 
		if(ans>dist[x2][y2][i]){
			ans = dist[x2][y2][i];
			//printf("ans jd: %d hadap ke: %d\n",ans,i);
		}
		//printf("\n");
	}
	if(ans==inf){printf("-1\n");}
	else{printf("%lld\n",ans);}
	return 0;
};