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
typedef vector<ii> vii;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

char mat[26][26];

int n,m;

int dfs(int x, int y, char awal, char akhir) {
	mat[x][y] = akhir;
	int cnt = 1;

	for(int i=0;i<4;i++){
		int xbaru = x + dx[i], ybaru = y + dy[i];
		if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < m) {
			if(mat[xbaru][ybaru] == awal) {
				mat[xbaru][ybaru] = akhir;
				cnt += dfs(xbaru, ybaru, awal, akhir);
			}
		}
	}

	return cnt;
}

bool canMakeProgress(int x, int y) {
	for(int i=x;i>=0;i--){
		if(mat[i][y] != '.'){return true;}
	}
	return false;
}

void fall() {
	int i,j;
	for(j=0;j<m;j++){
		for(i=n-1;i>=0;i--){
			if(mat[i][j] == '.' && canMakeProgress(i,j)){
				//swap ke atas
				for(int k=i;k>=1;k--){
					swap(mat[k][j], mat[k-1][j]);
				}
				i++;
			}
		}
	}
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	
	int maks = 0;
	int x, y;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			char awal = mat[i][j];
			char akhir = '.';

			int ans = dfs(i,j,awal,akhir);
			
			int nilai = ans*(ans-1);
			if(maks < nilai) {
				maks = nilai;
				x = i; y = j;
			}
			dfs(i,j,akhir, awal);
		}
	}


	dfs(x,y,mat[x][y], '.');
	fall();

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(j){printf(" ");}
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}

	return 0;
};