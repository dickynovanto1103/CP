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
typedef pair<ll,ii> iii;
typedef vector<ii> vii;

const int maxn = 255;
string kata[maxn];
ll total[maxn][maxn];
bool isVisited[maxn][maxn];
queue<iii> q;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	int n,m,i,j,k;
	ll dasar,p;
	scanf("%d %d %lld %lld",&n,&m,&dasar,&p);
	memset(total,0,sizeof total);
	for(i=0;i<n;i++){cin>>kata[i];}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int bil = (int)kata[i][j];
			if(bil>=65 && bil<=90){
				memset(isVisited,false,sizeof isVisited);
				ll noise = (bil-64)*dasar;
				q.push(mp(noise,ii(i,j)));
				total[i][j]+=noise;
				while(!q.empty()){
					//printf("test\n");
					iii front = q.front(); q.pop();
					ll tingkatNoise = front.first;
					int x = front.second.first, y = front.second.second;
					isVisited[x][y] = true;
					if(tingkatNoise==0){continue;}
					for(k=0;k<4;k++){
						int xbaru = x+dx[k], ybaru = y+dy[k];
						if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
							if(kata[xbaru][ybaru]!='*' && !isVisited[xbaru][ybaru]){
								ll noiseDiTetangga = tingkatNoise/2;
								total[xbaru][ybaru]+=noiseDiTetangga;
								isVisited[xbaru][ybaru] = true;
								q.push(mp(noiseDiTetangga,ii(xbaru,ybaru)));
							}
						}
					}
				}
				// printf("sementara\n");
				// for(k=0;k<n;k++){
				// 	for(int l=0;l<m;l++){
				// 		if(l){printf(" ");}
				// 		printf("%lld",total[k][l]);
				// 	}
				// 	printf("\n");
				// }
			}
		}
	}
	int cnt = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			if(total[i][j]>p){
				cnt++;
			}
		}
		//printf("\n");
	}
	printf("%d\n",cnt);
	return 0;
	
};