#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define bawah 0
#define kanan 1
#define kiri 2
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 502;
int memo[maxn][maxn][3];
int a[maxn][maxn];
int r,c;

int solve(int row, int col, int arah){
	// printf("row: %d col: %d\n",row,col);
	if(row==r){
		// printf("sudah diujung\n");
		return 0;
	}
	if(col<1 || col>c){
		// printf("pinggir kolom\n");
		return 0;
	}
	// if(arah==kanan && a[row][col+1]==1){return memo[row][col][arah] = 0;}
	// if(arah==kiri && a[row][col-1]==1){return memo[row][col][arah] = 0;}
	if(memo[row][col][arah]!=-1){return memo[row][col][arah];}
	if(a[row+1][col]==0){
		// printf("turun\n");
		if(arah!=bawah){return memo[row][col][arah] = solve(row,col,bawah);}//ubah orientasi ke bawah aja
		else{return memo[row][col][arah] = solve(row+1,col,bawah);}//turun
		
	}
	else{//nabrak
		if(arah==bawah){
			memo[row][col][arah] = 1+solve(row,col-1,kiri) + solve(row,col+1,kanan);	
		}else if(arah==kiri){
			memo[row][col][arah] = solve(row,col-1,kiri);
		}else if(arah==kanan){
			memo[row][col][arah] = solve(row,col+1,kanan);
		}
		return memo[row][col][arah];
		// printf("nabrak\n");
		
	}
}

int main(){
	int i,j,k,n;
	int a1,b1,a2,b2;
	scanf("%d %d %d",&r,&c,&n);
	
	memset(a,0,sizeof a);
	memset(memo,-1,sizeof memo);
	while(n--){
		scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
		for(i=a1;i<=a2;i++){
			for(j=b1;j<=b2;j++){
				a[i][j] = 1;
			}
		}

		
	}
	int ans = 0;
	for(i=1;i<=c;i++){
		int jawab = solve(0,i,bawah);
		//printf("i: %d jawab: %d\n",i,jawab);
		ans = max(ans,jawab);
	}
	printf("%d\n",ans);
	return 0;
};