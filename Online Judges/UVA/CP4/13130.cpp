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
	while(n--){
		int prev = -1;
		bool valid = true;
		for(int i=0;i<5;i++){
			int num;
			scanf("%d",&num);
			if(prev == -1) {
				prev = num;
			}else if(num != (prev + 1)){
				valid = false;
			}
			prev = num;
		}
		if(valid){
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