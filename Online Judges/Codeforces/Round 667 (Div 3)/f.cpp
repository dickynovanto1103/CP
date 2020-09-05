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

int n,k;
int dp[201][201][201]; //dp[idx][s on left][change left]
string s,t;
int secondRightCnt[202];

int occ(){
	char first = t[0], second = t[1];
	int n = s.size();
	int ans = 0;
	int i,j;
	for(i=0;i<n;i++){
		if(s[i] == first) {
			for(j=i+1;j<n;j++){
				if(s[j] == second) {
					ans++;
				}
			}
		}
	}
	return ans;
}

int solve(int idx, int sLeft, int moveLeft) {
	if(idx == n){return 0;}
	if(moveLeft == 0){return 0;}
	int& ans = dp[idx][sLeft][moveLeft];
	if(ans != -1){return ans;}
	int nextSLeft = sLeft;
	if(s[idx] == t[0]){nextSLeft++;}
	int ans1 = solve(idx+1, nextSLeft, moveLeft); //skip
	char first = t[0], second = t[1];
	int ans2 = 0, ans3 = 0;
	if(s[idx] != first) {
		//try to change to first
		//do if statement, if s[idx] == second, then need to subtract
		int tambah = secondRightCnt[idx+1];
		int kurang = 0;
		if(s[idx] == second) {
			kurang = sLeft;
		}
		if(second == first) {
			kurang -= sLeft;
		}
		ans2 = tambah - kurang + solve(idx+1, sLeft + 1, moveLeft-1);
	}
	if(s[idx] != second) {
		int tambah = sLeft;
		int kurang = 0;
		if(s[idx] == first){
			kurang = secondRightCnt[idx+1];
		}
		if(second == first) {
			kurang -= secondRightCnt[idx+1];
		}
		ans3 = tambah - kurang + solve(idx+1, sLeft, moveLeft-1);
	}
	ans = max(max(ans1, ans2), ans3);
	return ans;
}

int main(){
	int i,j;
	memset(dp, -1, sizeof dp);
	scanf("%d %d",&n,&k);
	cin>>s>>t;
	int occurence = occ();
	for(i=n-1;i>=0;i--){
		if(i < (n-1)){
			secondRightCnt[i] = secondRightCnt[i+1];
		}
		if(s[i] == t[1]){
			secondRightCnt[i]++;
		}
		// printf("secondRightCnt[%d]: %d\n",i, secondRightCnt[i]);
	}

	int ans = solve(0, 0, k);
	// for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++){
	// 		for(int l=0;l<=k;l++){
	// 			printf("%d %d %d => %d\n",i,j,l, dp[i][j][l]);
	// 		}
	// 	}
	// }
	// printf("dp: %d\n",dp[6][3][0]);
	printf("%d\n",ans + occurence);

	return 0;
};