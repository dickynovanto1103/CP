/*iterate 2 nested loops for the row
//inside 2 nested loop:
	I maintain an 1D array...each element will be calculated first, then later we find the min suffix
	the value of f[c]
	iterate c (column) from 4 to m
	f[c] = banyak 1 di tengah (from column 1 sampe c-1) - banyak 1 di border kanan (column kanan) - banyak 1 di border atas (column 1 sampe c-1) - banyak 1 di border bawah (column 1 sampe c-1) + 2 * (c - 1) + r2 - r1 - 1
	lalu loop to get suffix min di array f, f[c] = min(f[c], f[c+1], ... f[m])

	then getting the answer
	iterate from 1 until m-3
	current answer = f[c+3] - banyak 1 di tengah (column 1 sampe c) + banyak 1 di border atas (column 1 sampe c) + banyak 1 di border bawah (column 1 sampe c) - banyak 1 di border kanan - 2 * c + r2 - r1 - 1
*/	

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

int pref[405][404];

int calc(int r1, int r2, int c1, int c2) {
	int ans = pref[r2][c2];
	if(r1){ans -= pref[r1-1][c2];}
	if(c1){ans -= pref[r2][c1-1];}
	if(r1 && c1){ans += pref[r1-1][c1-1];}
	assert(ans >= 0);
	// printf("calc r1: %d c1: %d r2: %d c2: %d = %d\n", r1,c1,r2,c2, ans);
	return ans;
}

int inv(int r1, int r2, int c1, int c2) {
	return (r2 - r1 + 1) * (c2 - c1 + 1) - calc(r1,r2,c1,c2);
}

int main(){
	int n,m;
	int tc;
	scanf("%d",&tc);
	char s[404];
	while(tc--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;j<m;j++){
				pref[i][j] = s[j] == '1';
				if(i){pref[i][j] += pref[i-1][j];}
				if(j){pref[i][j] += pref[i][j-1];}
				if(i && j){pref[i][j] -= pref[i-1][j-1];}
			}
		}

		int ans = inf;
		for(int row=0;row<n;row++){
			for(int col=0;col<m;col++){
				for(int r2 = row+4;r2<n;r2++){
					for(int c2 = col+3;c2<m;c2++){
						int cur = calc(row+1, r2-1, col+1, c2-1);
						if(cur > ans){
							break;
						}
						cur += inv(row, row, col+1, c2-1);
						if(cur > ans){
							break;
						}
						cur += inv(r2, r2, col+1, c2-1);
						if(cur > ans){
							break;
						}
						cur += inv(row+1, r2-1, col, col);
						if(cur > ans){
							break;
						}
						cur += inv(row+1, r2-1, c2, c2);
						// printf("cur: %d")
						if(cur < ans){
							ans = cur;
						}
					}
				}
			}
		}

		printf("%d\n", ans);;
	}
	
	return 0;
};