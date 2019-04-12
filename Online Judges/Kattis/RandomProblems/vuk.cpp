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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 501;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int dist[maxn][maxn];
string kata[maxn];
int n,m;
ii koorJ, koorV;
bool isVisited[maxn][maxn];

bool isValid(int x, int y) {
	return x>=0 && x<n && y>=0 && y<m;
}

bool bisa(int mid) {
	int x = koorV.first, y = koorV.second;
	queue<ii> q;
	q.push(ii(x,y));
	
	int i;
	int cnt = 0;
	while(!q.empty()){
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		// printf("x: %d y: %d\n",x,y);
		isVisited[x][y] = true;
		printf("%d %d %d\n",x,y,cnt++);
		for(i=0;i<4;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(isValid(xbaru,ybaru) && !isVisited[xbaru][ybaru] && dist[xbaru][ybaru] >= mid){
				// isVisited[xbaru][ybaru] = true;
				printf("yang dipush: %d %d\n",xbaru, ybaru);
				q.push(ii(xbaru,ybaru));
			}
		}
	}
	if(isVisited[koorJ.first][koorJ.second]){return true;}
	return false;
}

int main(){
	FastSlowInput
	int i,j;
	cin>>n>>m;
	// scanf("%d %d",&n,&m);

	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	
	
	queue<ii> q;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			dist[i][j] = inf;
			char kar = kata[i][j];
			if(kar == '+'){
				dist[i][j] = 0;
				q.push(ii(i,j));
			}else if(kar == 'J'){
				koorJ = ii(i,j);
			}else if(kar == 'V'){
				koorV = ii(i,j);
			}
		}
	}

	while(!q.empty()){
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		for(i=0;i<4;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(isValid(xbaru, ybaru)){
				if(dist[xbaru][ybaru] == inf){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					q.push(ii(xbaru, ybaru));
				}
			}
		}
	}
	int kiri = 0, kanan = dist[koorV.first][koorV.second], mid, ans = -1;
	while(kiri <= kanan){
		mid = (kiri+kanan)/2;
		// printf("kiri: %d kanan: %d\n",kiri, kanan);
		memset(isVisited, false, sizeof isVisited);
		if(bisa(mid)){
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	
	// printf("%d\n",ans);
	cout<<ans<<endl;
	// for(i=0;i<n;i++){
	// 	for(j=0;j<m;j++){
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// int ans = 0;
	// for(i=0;i<4;i++){
	// 	int xbaru = x + dx[i], ybaru = y + dy[i];
	// 	if(isValid(xbaru,ybaru)) {
	// 		ans = max(ans, dp[xbaru][ybaru]);
	// 	}
	// }
	// ans = min(ans, dist[x][y]);
	// printf("%d\n",ans);

	return 0;
};