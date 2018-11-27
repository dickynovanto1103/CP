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

int r,c;
const int mod = 1e9 + 7;
string kata[15];
int dp[1001][14][1<<14][2];

// bool isAngkaValid(int bil, int col){
// 	for(int i=0;i<r;i++){
// 		if((bil & (1<<i)) != 0){
// 			if(kata[i][col] == 'v'){return false;}
// 		}
// 	}
// 	return true;
// }

// int solve(int row, int col, int bitmask, int colSebelumMarked){
// 	// printf("col: %d bitmask: %d r: %d\n",col,bitmask, r);
// 	if(row == r){
// 		return 0;
// 	}
// 	if(col == c){
// 		if(bitmask == ((1<<r) - 1)){return 1;}
// 		else{return 0;}
// 	}
// 	if(dp[col][bitmask][colSebelumMarked] != -1){return dp[col][bitmask][colSebelumMarked];}
// 	int ans = 0, start;
// 	if(colSebelumMarked == 0){
// 		start = 1;
// 	}else{
// 		start = 0;
// 	}
// 	bool kena = false;
// 	for(int i=start;i<(1<<r);i++){
// 		if(!isAngkaValid(i, col)){continue;}
// 		kena = true;
// 		if(i==0){
// 			ans += solve(col+1, bitmask, 0);
// 			ans %= mod;
// 		}else{
// 			ans += solve(col+1, bitmask | i, 1);
// 			ans %= mod;
// 		}
// 	}
// 	if(!kena){
// 		if(colSebelumMarked){
// 			ans += solve(col+1, bitmask, 0);
// 			ans %= mod;
// 		}
// 	}

// 	return dp[col][bitmask][colSebelumMarked] = ans;
// }

int main(){
	int i,j;
	
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++){cin>>kata[i];}
	memset(dp, -1, sizeof dp);
	// int ans = solve(0, 0, 1);
	// printf("%d\n",ans);
	return 0;
};