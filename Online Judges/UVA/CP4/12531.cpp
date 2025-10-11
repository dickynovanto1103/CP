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

map<int, bool> degrees;

int findDegree(int h, int m) {
	int degreeFromM = 6 * m;
	int additionMoveDegree = m / 12 * 6;
	int degreeFromH = h * 360 / 12;
	int diff = abs((degreeFromH + additionMoveDegree) - degreeFromM);
	if(diff > 180) {
		diff = 360 - diff;
	}

	return diff;
}

void solve(){
	for(int i=0;i<12;i++){
		for(int j=0;j<60;j++){
			int degree = findDegree(i,j);
			degrees[degree] = true;
		}
	}

	int q;
	while(scanf("%d",&q) == 1) {
		if(degrees[q]) {
			puts("Y");
		}else{
			puts("N");
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