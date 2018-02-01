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
typedef pair<ll,ii> iii;
typedef vector<ii> vii;

const int maxn = 301;
ll dist[maxn][maxn];
ll a[maxn][maxn];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int main(){
	int tc,i,j,k,r,c;
	string kata[maxn];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d: ",tt);
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){cin>>kata[i];}
		ii indeksY;
		vii listTransportal;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				dist[i][j] = inf;
				if(kata[i][j]=='Y'){indeksY = ii(i,j); a[i][j] = 0;}
				else if(kata[i][j]=='T'){listTransportal.pb(ii(i,j)); a[i][j]=0;}
				else if(kata[i][j]=='*'){a[i][j] = 1;}
				else if(kata[i][j]=='#'){a[i][j] = 4;}
				else{a[i][j]=0;}
			}
		}
		/*printf("a: \n");
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(j){printf(" ");}
				printf("%d",a[i][j]);
			}
			printf("\n");
		}*/
		dist[indeksY.first][indeksY.second] = 0;
		priority_queue<iii, vector<iii>, greater<iii> > pq; pq.push(make_pair(0,ii(indeksY.first,indeksY.second)));
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			ll d = front.first;
			int x = front.second.first, y = front.second.second;
			if(d > dist[x][y]){continue;}
			for(i=0;i<4;i++){
				int xbaru = x+dx[i], ybaru = y+dy[i];
				if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
					if(kata[xbaru][ybaru]!='#'){
						if(dist[xbaru][ybaru] > dist[x][y] + a[xbaru][ybaru]){
							dist[xbaru][ybaru] = dist[x][y] + a[xbaru][ybaru];
							pq.push(make_pair(dist[xbaru][ybaru],ii(xbaru,ybaru)));
						}
					}
				}
			}
		}
		ll ans = inf;
		for(i=0;i<listTransportal.size();i++){
			ii koordinat = listTransportal[i];
			int x = koordinat.first, y = koordinat.second;
			ans = min(ans,dist[x][y]);
		}
		if(ans==inf){printf("-1\n");}
		else{printf("%d\n",ans);}
	}
	return 0;
};