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
	int h, w;
	// printf("halo\n");
	while(scanf("%d %d",&h,&w) != EOF) {
		scanf("    ");
		// printf("%d %d\n",h,w);
		int cntSides = 0;
		int cntDots = 0;
		for(int i=0;i<h;i++){
			bool isOutside = true;
			
			for(int r=0;r<w;r++){
				char c;
				scanf("%c",&c);	
				if(r == w-1){
					scanf("\n");
				}				

				// printf("%c",c);
				if(c == '/' || c == '\\') {
					cntSides++;
					isOutside = !isOutside;
				}else if(!isOutside){
					cntDots++;
				}
			}
			// puts("");

		}
		
		assert(cntSides % 2 == 0);
		printf("%d\n", cntSides / 2 + cntDots);
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