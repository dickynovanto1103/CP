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
	int hh,mm;
	scanf("%d:%d", &hh, &mm);
	int h = 12-hh;
	int m = 60 - mm;
	if(m == 60){m = 0;}
	if(m > 0) {
		h--;
	}
	if(h <=0) {
		h += 12;
	}

	printf("%.2d:%.2d\n", h, m);

}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};