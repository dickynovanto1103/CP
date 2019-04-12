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

queue<ii> q;

int dist[251][251];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
string kata[251];

int maksDist;

void bfs(int r, int c) {
	while(!q.empty()){
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		for(int i=0;i<4;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(xbaru >= 0 && xbaru < r && ybaru >= 0 && ybaru < c) {
				if(dist[xbaru][ybaru] == inf){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					maksDist = max(maksDist, dist[xbaru][ybaru]);
					q.push(ii(xbaru, ybaru));
				}
			}
		}
	}
}

int calc(ii a, ii b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void minim(int &a, int b){
	a = min(a, b);
}
void maks(int &a, int b){
	a = max(a, b);
}

bool can(int mid, int r, int c) {
	int i,j;

	int min1 = inf, maks1 = -inf, min2 = inf, maks2 = -inf;

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(dist[i][j] > mid){
				// printf("i: %d j: %d dist: %d\n",i,j, dist[i][j]);
				minim(min1, i+j);
				minim(min2, i-j);
				maks(maks1, i+j);
				maks(maks2, i-j);
			}
		}
	}

	// printf("min1: %d maks1: %d min2: %d maks2: %d\n",min1, maks1, min2, maks2);
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(kata[i][j] == '0'){
				int jarak1 = abs(i+j - min1);
				int jarak2 = abs(i+j - maks1);
				int jarak3 = abs(i-j - min2);
				int jarak4 = abs(i-j - maks2);
				// printf("skrg i: %d j: %d jarak1: %d jarak2: %d jarak3: %d jarak4: %d\n",i,j,jarak1,jarak2,jarak3,jarak4);
				if(!(jarak1 > mid || jarak2 > mid || jarak3 > mid || jarak4 > mid)){return true;}
			}
		}
	}
	return false;

}

int main(){
	int tc,i,j,r,c;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		maksDist = 0;
		printf("Case #%d: ",tt);
		scanf("%d %d",&r,&c);
		
		
		for(i=0;i<r;i++){
			cin>>kata[i];
			for(j=0;j<c;j++){
				if(kata[i][j] == '1'){
					dist[i][j] = 0;
					q.push(ii(i,j));
				}else{
					dist[i][j] = inf;	
				}
			}
		}
		//bfs dulu dr 1 ke 0
		bfs(r,c);
		int kiri = 0, kanan = maksDist, mid, ans = maksDist;
		while(kiri <= kanan) {
			mid = (kiri+kanan)/2;
			// printf("mid: %d\n",mid);
			if(can(mid, r, c)){
				ans = mid;
				// printf("ans: %d\n",ans);
				kanan = mid-1;
			}else{
				kiri = mid+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};