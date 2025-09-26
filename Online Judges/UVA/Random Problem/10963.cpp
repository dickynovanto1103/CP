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
	scanf("%d",&n);
	int a, b;
	int selisih = -1;
	int valid = true;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		int diff = a - b;
		if(selisih == -1) {
			selisih = diff;
		}else if(selisih != diff) {
			valid = false;
		}
	}

	if(valid) {
		puts("yes");
	}else{
		puts("no");
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
		if(tc > 0) {
			puts("");
		}
	}

	return 0;
};