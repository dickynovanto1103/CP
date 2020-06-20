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

int main(){
	int n,i,j;
	scanf("%d",&n);
	vii p;
	// bool map[10][10];
	// memset(map, false, sizeof map);
	p.pb(ii(0,0));
	p.pb(ii(0,1));
	int tambah = 0;
	int lastCol = 0;
	for(i=1;i<=n;i++){
		for(j=0;j<3;j++){
			p.pb(ii(i, j+tambah));
			lastCol = j+tambah;
		}
		tambah++;
	}
	p.pb(ii(n+1,lastCol));
	p.pb(ii(n+1,lastCol-1));
	// printf("0 0 dan 2 %d\n",2*n);
	// map[0][0] = map[2][2*n] = true;
	printf("%d\n",int(p.size()));
	for(ii po: p){
		int x = po.first, y = po.second;
		printf("%d %d\n",x,y);
		// map[x][y] = true;
	}

	// for(i=0;i<n+2;i++){
	// 	for(j=0;j<2*n+1;j++){
	// 		// printf("i: %d j: %d\n",i,j);
	// 		if(map[i][j]){printf("*");}
	// 		else{printf(" ");}
	// 	}
	// 	printf("\n");
	// }

	
	return 0;
};