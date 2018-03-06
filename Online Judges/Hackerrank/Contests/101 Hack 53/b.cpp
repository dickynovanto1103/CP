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
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;

const int maxn = 101;
bool isVisited[maxn][maxn];

int main(){
	int n,m,i,j,x,y;
	scanf("%d %d %d %d",&n,&m,&x,&y);

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			isVisited[i][j] = false;
		}
	}
	for(j=1;j<=x;j++){isVisited[1][j] = true;}
	int batas = m-y;
	for(j=m;j>batas;j--){
		isVisited[n][j] = true;
	}
	int sisa = n*m - x - y;
	if(sisa%2==1){printf("NO\n"); return 0;}
	vector<iiii> listPair;
	//kasus khusus klo di ujung kiri bawah tinggal 1
	// if(!isVisited[n][1] && isVisited[n][2]){
	// 	ii pas1 = ii(n,1);
	// 	ii pas2 = ii(n-1,1);
		
	// 	iiii jawab = make_pair(pas1,pas2);
	// 	listPair.pb(jawab);
	// 	isVisited[n][1] = true; isVisited[n-1][1] = true;
	// }
	// //kalo di kanna atas tinggal 1
	// if(!isVisited[1][m] && isVisited[1][m-1]){
	// 	ii pas1 = ii(1,m);
	// 	ii pas2 = ii(2,m);
	// 	// printf("dipush: %d %d %d %d\n",1,m,1,m-1);
	// 	iiii jawab = make_pair(pas1,pas2);
	// 	listPair.pb(jawab);
	// 	isVisited[1][m] = true; isVisited[2][m] = true;
	// }

	// //secara horizontal dulu

	// for(i=1;i<=n;i++){
	// 	for(j=1;j<m;j++){
	// 		// printf("i: %d j: %d\n",i,j);
	// 		if(!isVisited[i][j] && isVisited[i][j+1] && i<n) {
	// 			ii pas1 = ii(i,j);
	// 			ii pas2 = ii(i+1,j);
	// 			// printf("dipush1: %d %d %d %d\n",i,j,i+1,j);
	// 			iiii jawab = make_pair(pas1,pas2);
	// 			listPair.pb(jawab);
	// 			isVisited[i][j] = true; isVisited[i+1][j] = true;
	// 			continue;
	// 		}
	// 		if(!isVisited[i][j] && !isVisited[i][j+1]){
	// 			ii pas1 = ii(i,j);
	// 			ii pas2 = ii(i,j+1);
	// 			// printf("dipush2: %d %d %d %d\n",i,j,i,j+1);
	// 			iiii jawab = make_pair(pas1,pas2);
	// 			listPair.pb(jawab);
	// 			isVisited[i][j] = true; isVisited[i][j+1] = true;
	// 		}
	// 	}
	// }

	// // for(i=1;i<=n;i++){
	// // 	for(j=1;j<=m;j++){
	// // 		if(j>1){printf(" ");}
	// // 		printf("%d",isVisited[i][j]);
	// // 	}
	// // 	printf("\n");
	// // }
	// //secara vertikal
	// for(j=1;j<=m;j++){
	// 	for(i=1;i<n;i++){

	// 		if(!isVisited[i][j] && !isVisited[i+1][j]){
	// 			ii pas1 = ii(i,j);
	// 			ii pas2 = ii(i+1,j);
	// 			// printf("i: %d j: %d nilai: %d %d\n",i,j, isVisited[j][i], isVisited[j][i+1]);
	// 			// printf("dipush3: %d %d %d %d\n",i,j,i+1,j);
	// 			iiii jawab = make_pair(pas1,pas2);
	// 			listPair.pb(jawab);
	// 			isVisited[i][j] = true; isVisited[i+1][j] = true;
	// 		}
	// 	}
	// }
	// int expected = sisa/2;
	// int ukuran = listPair.size();

	// if(ukuran!=expected){printf("NO\n"); return 0;}

	//metode 2
	int kolom1 = x+1;
	for(j=kolom1;j<=m;j++){
		ii pas1 = ii(1,j);
		ii pas2 = ii(2,j);
		// printf("yang dipush: %d %d %d %d\n",1,j,1+1,j);
		iiii jawab = make_pair(pas1,pas2);
		listPair.pb(jawab);
		isVisited[1][j] = true; isVisited[2][j] = true;
	}

	int kolom2 = batas;
	for(j=batas;j>=1;j--){
		ii pas1 = ii(n,j);
		ii pas2 = ii(n-1,j);
		// printf("yang dipush: %d %d %d %d\n",n,j,n-1,j);
		iiii jawab = make_pair(pas1,pas2);
		listPair.pb(jawab);
		isVisited[n][j] = true; isVisited[n-1][j] = true;
	}

	//secara horizontal dulu

	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){
			// printf("i: %d j: %d\n",i,j);
			if(!isVisited[i][j] && isVisited[i][j+1] && i<n) {
				ii pas1 = ii(i,j);
				ii pas2 = ii(i+1,j);
				// printf("dipush1: %d %d %d %d\n",i,j,i+1,j);
				iiii jawab = make_pair(pas1,pas2);
				listPair.pb(jawab);
				isVisited[i][j] = true; isVisited[i+1][j] = true;
				continue;
			}
			if(!isVisited[i][j] && !isVisited[i][j+1]){
				ii pas1 = ii(i,j);
				ii pas2 = ii(i,j+1);
				// printf("dipush2: %d %d %d %d\n",i,j,i,j+1);
				iiii jawab = make_pair(pas1,pas2);
				listPair.pb(jawab);
				isVisited[i][j] = true; isVisited[i][j+1] = true;
			}
		}
	}	
	
	//secara vertikal
	for(j=1;j<=m;j++){
		for(i=1;i<n;i++){

			if(!isVisited[i][j] && !isVisited[i+1][j]){
				ii pas1 = ii(i,j);
				ii pas2 = ii(i+1,j);
				
				iiii jawab = make_pair(pas1,pas2);
				listPair.pb(jawab);
				isVisited[i][j] = true; isVisited[i+1][j] = true;
			}
		}
	}
	int expected = sisa/2;
	int ukuran = listPair.size();
	// printf("ukuran: %d expected: %d\n",ukuran,expected);
	if(ukuran!=expected){printf("NO\n"); return 0;}


	printf("YES\n%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		iiii jawab = listPair[i];
		ii pas1 = jawab.first, pas2 = jawab.second;

		int x1 = pas1.first, y1 = pas1.second, x2 = pas2.first, y2 = pas2.second;
		printf("%d %d %d %d\n",x1,y1,x2,y2);
	}
	return 0;
};