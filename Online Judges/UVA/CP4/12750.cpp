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

void solve(int tcNum){
	int n;
	scanf("%d",&n);
	int cntNotWin = 0;
	int matchIdxSacked = -1;
	for(int i=1;i<=n;i++){
		char c;
		scanf(" %c",&c);
		if(c == 'D' || c == 'L') {
			cntNotWin++;
			if(cntNotWin == 3 && matchIdxSacked == -1) {
				matchIdxSacked = i;
			}
		}else{
			cntNotWin = 0;
		}
	}

	printf("Case %d: ", tcNum);
	if(matchIdxSacked == -1) {
		puts("Yay! Mighty Rafa persists!");
	}else{
		printf("%d\n", matchIdxSacked);
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		solve(tt);
	}

	return 0;
};