#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define touched 2
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

int a[400][4000];
int vis[4000][400];
bool isPinggir[400][400], isPojok[400][400];;

int dx[] = {0,-1,-1,0,1,1};
int dy[] = {-1,-1,0,1,1,0};
int maksRow, maksCol;
ll ans = 0;

void dfs(int x, int y){
	vis[x][y] = 2;
	
	for(int i=0;i<6;i++){
		int xbaru = x + dx[i], ybaru = y + dy[i];
		
		if(xbaru>=0 && xbaru<maksRow && ybaru>=0 && ybaru<maksCol){
			if(a[xbaru][ybaru] != inf){
				if(vis[xbaru][ybaru] == -1){
					ans++;
					// printf("dari x: %d y: %d ke xbaru: %d ybaru: %d ans jd: %lld\n",x,y,xbaru,ybaru,ans);
				}else if(vis[xbaru][ybaru] == 1){
					dfs(xbaru,ybaru);
				}	
			}
			
		}
	}
}

void cetakVis(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(j){printf(" ");}
			printf("%d",vis[i][j]);
		}
		printf("\n");
	}
}

vii listPinggir, listPojok;

int main(){
	int r,k;
	scanf("%d %d",&r,&k);
	int idx = 0, bil = 1;
	int i,j;
	ii listBil[200000];
	if(r==1){printf("6\n"); return 0;}
	memset(isPinggir, false, sizeof isPinggir);
	memset(isPojok, false, sizeof isPojok);
	for(i=0;i<400;i++){
		for(j=0;j<400;j++){
			a[i][j] = inf;
		}
	}

	for(i=0;i<r;i++){
		int batas = r + idx;
		for(j=0;j<batas;j++){
			if(i==0){
				listPinggir.pb(ii(i,j));
				isPinggir[i][j] = true;
			}else{
				if(j == 0 || j == (batas-1)){
					listPinggir.pb(ii(i,j));
					isPinggir[i][j] = true;
				}
			}
			if(i == 0 || i == (r-1)){
				if(j == 0 || j==(batas-1)){
					listPojok.pb(ii(i,j));
					isPojok[i][j] = true;
				}
			}

			listBil[bil] = ii(i,j);
			a[i][j] = bil++;
		}
		idx++;
		if(idx == r){break;}
	}

	int indeksAkhir = r + r - 2;
	maksRow = indeksAkhir + 2;
	maksCol = indeksAkhir + 2;
	// printf("maksRow: %d maksCol: %d\n",maksRow, maksCol);
	int tambah = i+1;
	idx-=2;
	int nextRow;
	int tambahKolom = 1;
	for(i=0;i<r;i++){
		int batas = r + idx;
		if(batas < r){break;}
		for(j=0;j<batas;j++){
			if((i+tambah)==(indeksAkhir)){
				listPinggir.pb(ii(i+tambah, j+tambahKolom));
				isPinggir[i+tambah][j+tambahKolom] = true;

			}else{
				if(j == 0 || j == (batas-1)){
					listPinggir.pb(ii(i+tambah, j+tambahKolom));
					isPinggir[i+tambah][j+tambahKolom] = true;
				}
			}
			if((i+tambah)==(indeksAkhir)){
				if(j == 0 || j==(batas-1)){
					listPojok.pb(ii(i + tambah,j+tambahKolom));
					isPojok[i+tambah][j+tambahKolom] = true;
				}
			}
			listBil[bil] = ii(i+tambah,j+tambahKolom);
			a[i+tambah][j+tambahKolom] = bil++;
		}
		tambahKolom++;
		nextRow = i+tambah+1;
		idx--;
		if(idx == r){break;}
	}

	for(i=0;i<400;i++){
		for(j=0;j<400;j++){
			vis[i][j] = 1;
		}
	}

	for(i=0;i<k;i++){
		int bil;
		scanf("%d",&bil);
		ii indeks = listBil[bil];
		int x = indeks.first, y = indeks.second;
		vis[x][y] = -1;
		if(isPinggir[x][y]){ans+=2;}
		if(isPojok[x][y]){ans++;}
	}
	for(i=0;i<listPinggir.size();i++){
		int x = listPinggir[i].first, y = listPinggir[i].second;
		if(vis[x][y] == -1 || vis[x][y] == 2){continue;}
		dfs(x,y);
	}
	
	printf("%lld\n",ans);
	
	return 0;
};