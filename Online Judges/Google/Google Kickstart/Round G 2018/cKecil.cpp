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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int maxn = 1e2 + 2;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	int tc,n,m,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int x1,y1,x2,y2,e;
		scanf("%d %d %d %d %d %d %d",&n,&m,&e,&x1,&y1,&x2,&y2);
		x1--; y1--; x2--; y2--;
		int a[maxn][maxn];
		int maksEnergi[maxn][maxn];

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				maksEnergi[i][j] = -inf;
				scanf("%d",&a[i][j]);
			}
		}
		maksEnergi[x1][y1] = e;
		priority_queue<iii> pq;
		pq.push(make_pair(maksEnergi[x1][y1], ii(x1,y1)));
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			int energi = front.first, x = front.second.first, y = front.second.second;
			if(energi < maksEnergi[x][y]){continue;}
			for(i=0;i<4;i++){
				int xbaru = x + dx[i], ybaru = y + dy[i];
				if(xbaru>=0 && xbaru < n && ybaru>=0 && ybaru < m){
					if(a[xbaru][ybaru] > -100000){
						if(maksEnergi[xbaru][ybaru] < (maksEnergi[x][y] + a[xbaru][ybaru])){
							maksEnergi[xbaru][ybaru] = maksEnergi[x][y] + a[xbaru][ybaru];
							pq.push(make_pair(maksEnergi[xbaru][ybaru], ii(xbaru, ybaru)));
						}
					}
				}
			}
		}
		// printf("maksEnergi: %d\n",maksEnergi[x1][y1]);
		if(maksEnergi[x2][y2] < 0){
			printf("-1\n");
		}else{
			printf("%d\n",maksEnergi[x2][y2]);
		}
	}
	return 0;
};