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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(){
	int n;
	while(scanf("%d",&n), n) {
		printf("Printing order for %d pages:\n", n);
		int numSheet = (n + 3) / 4;
		int pages[numSheet+1][2][2] = {};
		int side = 1;
		int pageNum = 1;


		for(int i=0;i<numSheet;i++){
			for(int j=0;j<2;j++){
				pages[i][j][side] = pageNum++;
				side = 1 - side;
				if(pageNum > n) {
					break;
				}
			}
			if(pageNum > n) {
				break;
			}
		}

		if(pageNum <= n) {
			for(int i=numSheet-1;i>=0;i--){
				for(int j=1;j>=0;j--){
					pages[i][j][side] = pageNum++;
					side = 1 - side;
					if(pageNum > n) {
						break;
					}
				}
				if(pageNum > n) {
					break;
				}
			}
		}
		
		for(int i=0;i<numSheet;i++){
			for(int j=0;j<2;j++){
				if(pages[i][j][0] == pages[i][j][1] && pages[i][j][0] == 0) {
					continue;
				}
				printf("Sheet %d, ", i + 1);
				if(j == 0){
					printf("front: ");
				}else{
					printf("back : ");
				}
				for(int k=0;k<2;k++){
					if(pages[i][j][k] == 0){printf("Blank");}
					else{
						printf("%d",pages[i][j][k]);
					}
					if(k == 0) {printf(", ");}
					else{puts("");}
				}
			}
		}
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};