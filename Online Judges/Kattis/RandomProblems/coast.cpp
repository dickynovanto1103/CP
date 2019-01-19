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

char kata[maxn][maxn];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m;

bool isValid(int x, int y){
	return x >= 0 && x < n && y>=0 && y < m;
}

int cnt = 0;

void floodFill(int r, int c) {
	int i,j;
	kata[r][c] = '3';
	for(i=0;i<4;i++){
		int xbaru = r + dx[i], ybaru = c + dy[i];
		if(isValid(xbaru, ybaru)) {
			if(kata[xbaru][ybaru] == '1') {
				cnt++;
			}else if(kata[xbaru][ybaru] == '0') {
				floodFill(xbaru, ybaru);
			}
		}
	}
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++){
		scanf("%s",kata[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i == 0 || i == (n-1)){
				if(kata[i][j] == '0'){floodFill(i,j);}
			}else{
				if(j == 0 || j == (m-1)){
					if(kata[i][j] == '0'){floodFill(i,j);}	
				}
				
			}
		}
	}
	// printf("cnt: %d\n", cnt);
	for(j=0;j<m;j++){
		if(kata[0][j] == '1'){cnt++;}
	}
	// printf("cnt1: %d\n", cnt);
	for(j=0;j<m;j++){
		if(kata[n-1][j] == '1'){cnt++;}
	}
	// printf("cnt2: %d\n", cnt);
	for(i=0;i<n;i++){
		if(kata[i][0] == '1'){cnt++;}
	}
	// printf("cnt3: %d\n", cnt);
	for(i=0;i<n;i++){
		if(kata[i][m-1] == '1'){cnt++;}
	}
	// printf("cnt: %d\n",cnt);

	printf("%d\n",cnt);
	return 0;
};