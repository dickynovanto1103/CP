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

int pre[405][405];

int calc1(int r1, int r2, int c1, int c2){
	return pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1];
}

int calc0(int r1, int r2, int c1, int c2) {
	return (r2-r1+1) * (c2-c1+1) - calc1(r1,r2,c1,c2);
}

auto const Calc(int r1, int r2, int c) {
	int rightBorder = calc0(r1+1, r2-1, c, c);
	int topBorderIncludingLastCol = calc0(r1,r1,0, c);
	int bottomBorderIncludingLastCol = calc0(r2,r2,0,c);
	int middleIncludingLastCol = calc1(r1+1,r2-1,0,c);

	int topBorderExcludingLastCol = calc0(r1,r1,0,c-1);
	int bottomBorderExcludingLastCol = calc0(r2,r2,0,c-1);
	int middleExcludingLastCol = calc1(r1+1,r2-1,0,c-1);
	return array<int, 3>({
		rightBorder, 
		topBorderIncludingLastCol + bottomBorderIncludingLastCol + middleIncludingLastCol, 
		topBorderExcludingLastCol + bottomBorderExcludingLastCol + middleExcludingLastCol
	});
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d%d",&n,&m);
		char s[405];
		for(i=1;i<=n;i++){
			scanf("%s", s+1);
			for(j=1;j<=m;j++){
				pre[i][j] = s[j] == '1';
				pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			}
		}

		int ans = inf;
		for(int r1=1;r1<=n;r1++){
			for(int r2=r1+4;r2<=n;r2++){
				//we create prefix minimum to get the number of 0 in right border to be turned into 1 in the left side, and number of 1 in the middle box
				int best = inf;
				for(int col=1;col<=m;col++){
					if(col - 3 >= 1){
						auto [right, include, exclude] = Calc(r1,r2,col-3);
						best = min(best, right - include);
						// printf("r1: %d r2: %d col: %d right: %d include: %d best: %d\n", r1,r2,col,right, include,best);

						array<int, 3> res = Calc(r1,r2,col);
						ans = min(ans, res[0] + res[2] + best);
						// printf("ans: %d\n",ans);
					}
				}
			}
		}

		printf("%d\n", ans);
	}
	return 0;
};