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
typedef pair<int,ii> iii;
typedef pair<ll,iii> iiii;

const int maxn = 110;
ll dist[maxn][maxn][maxn];
int dx[] = {1,0,0,1,1,0,1};
int dy[] = {0,1,0,1,0,1,1};
int dz[] = {0,0,1,0,1,1,1};

queue<iiii> pq;

int main(){
	int tc;
	int x,y,z,i,j,k;
	ll a,b,c;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %lld %lld %lld",&x,&y,&z,&a,&b,&c);
		for(i=0;i<=x;i++){
			for(j=0;j<=y;j++){
				for(k=0;k<=z;k++){
					dist[i][j][k] = inf;
				}
			}
		}
		
		dist[0][0][0] = 0;
		pq.push(mp(dist[0][0][0],mp(0,ii(0,0))));
		while(!pq.empty()){
			iiii front = pq.front(); pq.pop();
			ll d = front.first;
			int x1 = front.second.first,y1 = front.second.second.first,z1 = front.second.second.second;
			//printf("x1: %d y1: %d z1: %d\n",x1,y1,z1);

			if(dist[x1][y1][z1]<d){continue;}
			//if(x1==x && y1==y && z1==z){break;}
			for(i=0;i<7;i++){
				//printf("i: %d\n",i);
				int xbaru = x1+dx[i], ybaru = y1+dy[i], zbaru = z1+dz[i];
				if(xbaru>x || ybaru>y || zbaru>z){continue;}
				if(i>=0 && i<3){
					if(dist[xbaru][ybaru][zbaru]>(dist[x1][y1][z1]+a)){
						dist[xbaru][ybaru][zbaru] = dist[x1][y1][z1]+a;
						pq.push(mp(dist[xbaru][ybaru][zbaru],mp(xbaru,ii(ybaru,zbaru))));
					}
				}else if(i>=3 && i<6){
					if(dist[xbaru][ybaru][zbaru]>(dist[x1][y1][z1]+b)){
						dist[xbaru][ybaru][zbaru] = dist[x1][y1][z1]+b;
						pq.push(mp(dist[xbaru][ybaru][zbaru],mp(xbaru,ii(ybaru,zbaru))));
					}
				}else{
					if(dist[xbaru][ybaru][zbaru]>(dist[x1][y1][z1]+c)){
						dist[xbaru][ybaru][zbaru] = dist[x1][y1][z1]+c;
						pq.push(mp(dist[xbaru][ybaru][zbaru],mp(xbaru,ii(ybaru,zbaru))));
					}
				}
				
			}
		}
		printf("%lld\n",dist[x][y][z]);
	}
	return 0;
};