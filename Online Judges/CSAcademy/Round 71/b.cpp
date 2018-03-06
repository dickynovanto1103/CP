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

const int maxn = 501;

int counter[maxn][maxn];
int a[maxn][maxn];
ii bakalTujuan[maxn][maxn];
int n,m;

int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};

ii dfs(int x, int y){
	int k;
	int minim = a[x][y];
	ii tujuan = ii(-1,-1);
	if(bakalTujuan[x][y]!= ii(-1,-1)) {return bakalTujuan[x][y];}
	for(k=0;k<8;k++){
		int xbaru = x+dx[k], ybaru = y+dy[k];
		if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
			if(minim > a[xbaru][ybaru]){
				minim = a[xbaru][ybaru];
				tujuan = ii(xbaru,ybaru);
			}
		}
	}
	if(tujuan==ii(-1,-1)){return bakalTujuan[x][y] = ii(x,y);}
	else{return bakalTujuan[x][y] = dfs(tujuan.first, tujuan.second);}
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			bakalTujuan[i][j] = ii(-1,-1);
		}
	}
	int k;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			// int minim = a[i][j];
			// ii tujuan = ii(-1,-1);
			// for(k=0;k<8;k++){
			// 	int xbaru = i+dx[k], ybaru = j+dy[k];
			// 	if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
			// 		if(minim > a[xbaru][ybaru]){
			// 			minim = a[xbaru][ybaru];
			// 			tujuan = ii(xbaru,ybaru);
			// 		}
			// 	}
			// }
			// if(tujuan==ii(-1,-1)){bakalTujuan[i][j] = ii(i,j);}
			// else{bakalTujuan[i][j] = ii(bakalTujuan)}
			dfs(i,j);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			ii tujuan = bakalTujuan[i][j];
			counter[tujuan.first][tujuan.second]++;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(j){printf(" ");}
			printf("%d",counter[i][j]);
		}
		printf("\n");
	}

	return 0;
};