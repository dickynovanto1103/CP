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
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		bool valid = true;
		for(int i=0;i<13;i++){
			int num;
			scanf("%d",&num);
			if(num == 0) {
				valid = false;
			}
		}

		printf("Set #%d: ", tt);
		if(valid){
			puts("Yes");
		}else{
			puts("No");
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