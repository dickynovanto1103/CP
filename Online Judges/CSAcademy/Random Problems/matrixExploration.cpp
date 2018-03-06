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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

const int maxn = 1e3 + 4;

int dist[maxn][maxn];
bool isVisited[maxn][maxn];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
queue<iii> q;
int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	memset(isVisited,false,sizeof isVisited);
	string kata[maxn];
	for(i=0;i<n;i++){cin>>kata[i];}
	for(i=0;i<k;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		x--; y--;
		dist[x][y] = 0;
		isVisited[x][y] = true;
		q.push(make_pair(ii(x,y),dist[x][y]));
	}
	while(!q.empty()){
		iii front = q.front(); q.pop();
		int x = front.first.first, y = front.first.second, jarak = front.second;
		for(i=0;i<4;i++){
			int xbaru = x+dx[i], ybaru = y + dy[i];
			if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
				if(isVisited[xbaru][ybaru]){continue;}
				if(kata[xbaru][ybaru]=='.'){
					dist[xbaru][ybaru] = jarak + 1;
					q.push(make_pair(ii(xbaru,ybaru), dist[xbaru][ybaru]));
					isVisited[xbaru][ybaru] = true;		
				}
				
			}
		}
	}

	ll sum = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j]=='.'){

				sum+=dist[i][j];
				// printf("sum ditambah: %lld jadi: %lld\n",(ll)dist[i][j], sum);
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
};