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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

bool isJarakValid(int jarak, int minVal, int maksVal) {
	return minVal <= jarak && jarak <= maksVal;
}

int jarakMap[52][52];

int n,m;

bool isPinggir(int a, int b) {
	if(n == 2 || m == 2) {return true;}
	return a == 0 || a == n-1 || b == 0 || b == m-1;
}

void checkMapValidity() {
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			assert(1 <= jarakMap[i][j] && jarakMap[i][j] <= 1000);
		}
	}
}

ll dist[52][52];

void resetDist() {
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			dist[i][j] = inf;
		}
	}
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dijkstra(int a, int b) {
	resetDist();
	priority_queue<iii, viii, greater<iii> > pq;
	dist[a][b] = jarakMap[a][b];
	pq.push(iii(dist[a][b], ii(a, b)));
	while(!pq.empty()) {
		iii front = pq.top(); pq.pop();
		ll jarak = front.first;
		ii koor = front.second;
		int x = koor.first, y = koor.second;

		if(jarak > dist[x][y]) {continue;}

		for(int i=0;i<4;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < m) {
				if(dist[xbaru][ybaru] > (jarak + jarakMap[xbaru][ybaru])) {
					dist[xbaru][ybaru] = jarak + jarakMap[xbaru][ybaru];
					pq.push(iii(dist[xbaru][ybaru], ii(xbaru, ybaru)));
				}
			}
		}
	}
}

bool isFinalJarakValid(ll jarak, int a, int b, int c, int d) {
	dijkstra(a, b);

	// printf("jarak: %lld dist[%d][%d]: %lld\n",jarak, c, d, dist[c][d]);
	return dist[c][d] == jarak;
}

int main(){
	int tc,a,b,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		// cerr<<"Case "<<tt<<endl;
		printf("Case #%d: ", tt);

		scanf("%d %d %d %d",&n,&m,&a,&b);
		int minVal = n + m - 1, maksVal = (n + m - 1) * 1000;
		if(!isJarakValid(a, minVal, maksVal) || !isJarakValid(b, minVal, maksVal)) {
			printf("Impossible\n");
			continue;
		}

		memset(jarakMap, -1, sizeof jarakMap);

		printf("Possible\n");
		int val1 = a - (n + m -2);
		int val2 = b - (n + m - 2);
		assert(val1 >= 1); assert(val2 >= 1);

		jarakMap[0][0] = val1;
		jarakMap[0][m-1] = val2;
		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(jarakMap[i][j] == -1) {
					if(isPinggir(i,j)) {
						jarakMap[i][j] = 1;
					}else{
						jarakMap[i][j] = 1000;
					}
				}
			}
		}

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(j) {
					printf(" ");
				}
				printf("%d",jarakMap[i][j]);
			}
			printf("\n");
		}

		checkMapValidity();
		assert(isFinalJarakValid(a, 0,0,n-1,m-1));
		assert(isFinalJarakValid(b, 0,m-1, n-1,0));
	}
	
	return 0;
};