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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

char s[1010][1010];
int dp[1010][1010];

bool isNotPass(char kar) {
	return kar == 'x' || kar == '#';
}

int solve(int r, int c) {
	dp[0][0] = 1;
	int i,j;
	for(j=1;j<c;j++){
		if(isNotPass(s[0][j])){dp[0][j] = 0;}
		else{dp[0][j] = dp[0][j-1];}
	}
	for(i=1;i<r;i++){
		if(isNotPass(s[i][0])){dp[i][0] = 0;}
		else{dp[i][0] = dp[i-1][0];}
	}
	for(i=1;i<r;i++){
		for(j=1;j<c;j++){
			if(isNotPass(s[i][j])){dp[i][j] = 0;}
			else{dp[i][j] = dp[i][j-1] + dp[i-1][j];}
		}
	}
	return dp[r-1][c-1];
}

int main(){
	int r,c,i,j;
	scanf("%d %d",&r,&c);
	string com;
	cin>>com;
	for(i=0;i<r;i++){
		scanf("%s",s[i]);
	}
	s[0][0] = 'a';
	int row = 0, col = 0;
	int cntAtasBawah = 0, cntKiriKanan = 0;
	vii listKoor;
	for(i=0;i<com.length();i++){
		if(com[i] == '>'){
			col++;
			s[row][col] = 'a';

		}else{
			row++;
			s[row][col] = 'a';
		}
		if(s[row][col+1] == '.'){
			s[row][col+1] = 'x';
			listKoor.pb(ii(row, col+1));
		}
		if(col > 0 && s[row][col-1] == '.') {
			s[row][col-1] = 'x';
			listKoor.pb(ii(row, col-1));
		}
	}
	int ukuran = listKoor.size();
	for(i=0;i<ukuran;i++){
		cerr<<i+1<<" / "<<ukuran<<endl;
		ii koor = listKoor[i];
		int x = koor.first, y = koor.second;
		s[x][y] = '.';
		if(solve(r,c) == 1){

		}else{
			s[x][y] = 'x';
		}
	}
	for(i=0;i<r;i++){
		// for(j=0;j<c;j++){
		// 	if(s[i][j] == 'a'){
		// 		s[i][j] = '.';
		// 	}
		// }
		printf("%s\n",s[i]);
	}
	return 0;
};