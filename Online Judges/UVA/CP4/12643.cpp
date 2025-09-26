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

int getSection(int idx, int bagi) {
	return (idx + bagi - 1) / bagi;
}

void solve(){
	int n, i,j;
	while(scanf("%d %d %d",&n,&i,&j) == 3) {
		for(int tt=1;tt<=n;tt++){
			int bagi = (1<<tt); 
			// printf("bagi: %d\n", bagi);
			// printf("section i: %d = %d, section j: %d = %d\n", i, getSection(i, bagi), j, getSection(j, bagi));
			if(getSection(i, bagi) == getSection(j, bagi)) {
				printf("%d\n",tt);
				break;
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