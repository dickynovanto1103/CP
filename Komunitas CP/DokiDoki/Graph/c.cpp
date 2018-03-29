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

char kata[maxn][maxn], hasil[maxn][maxn];
int id[maxn][maxn], counter[maxn][maxn];
bool isVisited[maxn][maxn];
int nilai[maxn*maxn];
int n,m;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
queue<ii> q;

int floodFill(int x, int y, int idx) {
	int i,j;
	int ans = 1;
	isVisited[x][y] = true;
	id[x][y] = idx;
	q.push(ii(x,y));
	while(!q.empty()) {
		ii front = q.front(); q.pop();

		for(i=0;i<4;i++){
			int xbaru = front.first + dx[i], ybaru = front.second + dy[i];
			if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m) {
				if(!isVisited[xbaru][ybaru] && kata[xbaru][ybaru]=='.'){
					isVisited[xbaru][ybaru] = true;
					q.push(ii(xbaru,ybaru));
					ans++;
					id[xbaru][ybaru] = idx;
				}
			}
		}
	}
	return ans;
}

int main(){
	int i,j;
	memset(isVisited,false,sizeof isVisited);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%s",kata[i]);}
	// for(i=0;i<n;i++){
	// 	printf("%s\n",kata[i]);
	// }
	int idx = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(!isVisited[i][j] && kata[i][j] == '.'){
				int ans = floodFill(i,j,idx);
				nilai[idx] = ans;
				idx++;

			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j]=='*'){
				set<int> s;
				int ans = 1;
				for(int k=0;k<4;k++){
					int xbaru = i+dx[k], ybaru = j+dy[k];
					if(kata[xbaru][ybaru]=='.'){
						int indeks = id[xbaru][ybaru];
						if(s.count(indeks)==0){
							s.insert(indeks);
							ans+=nilai[indeks];
						}
					}
				}
				ans%=10;
				hasil[i][j] = ans+'0';
			}else{
				hasil[i][j] = '.';
			}
		}
	}

	for(i=0;i<n;i++){
		printf("%s\n",hasil[i]);
	}
	return 0;
};