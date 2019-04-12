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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 100010;
int dp[maxn][101][2];
string s;
int d,n;
const int mod = 1e9 + 7;

void add(int &a, int b){
	a += b;
	if(a < 0){a += mod;}
	if(a >= mod){
		a -= mod;
	}
}

int solve(int idx, int sisa, int isLebihKecil) {
	int i,j,k;
	if(idx == n){
		if(sisa == 0){return 1;}
		else{return 0;}
	}
	if(dp[idx][sisa][isLebihKecil]!=-1){return dp[idx][sisa][isLebihKecil];}
	int batas = (isLebihKecil ? 9: s[idx] - '0');
	int ans = 0;
	for(i=0;i<=batas;i++){
		if(i < batas){
			add(ans, solve(idx+1, (sisa + i) % d, 1));
		}else{
			add(ans, solve(idx+1, (sisa + i) % d, isLebihKecil));
		}
	}
	return dp[idx][sisa][isLebihKecil] = ans;
}

int main(){
	
	int i,j,k;
	cin>>s>>d;
	n = s.length();

	//bottom up

	// dp[0][0][0] = 1;
	// for(i=0;i<n;i++) {
	// 	for(j=0;j<d;j++){
	// 		for(k=0;k<2;k++){
	// 			int batas;
	// 			if(k == 0){
	// 				batas = s[i] - '0';
	// 			}else{
	// 				batas = 9;
	// 			}
	// 			// printf("k: %d batas: %d\n",k,batas);
	// 			for(int l=0;l<=batas;l++){
	// 				if(l < batas){
	// 					add(dp[i+1][(j + l) % d][1], dp[i][j][k]);
	// 					// printf("dp[%d][%d][%d] jd: %d\n",i+1,(j+l)%d, 1, dp[i+1][(j+l)%d][1]);
	// 				}
	// 				else{
	// 					add(dp[i+1][(j + l) % d][k], dp[i][j][k]);
	// 					// printf("dp[%d][%d][%d] jd: %d\n",i+1,(j+l)%d, k, dp[i+1][(j+l)%d][k]);
	// 				}
					
	// 			}
	// 		}
	// 	}
	// }
	// int ans = 0;
	// add(ans, dp[n][0][0]);
	// add(ans, dp[n][0][1]);
	// add(ans, -1);

	memset(dp, -1, sizeof dp);
	int ans = solve(0,0,0);
	add(ans, -1);
	printf("%d\n",ans);
	return 0;
};