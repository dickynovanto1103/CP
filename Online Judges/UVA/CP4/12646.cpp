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
	int a, b, c;
	while(scanf("%d %d %d",&a,&b,&c) != EOF) {
		int sum = a + b + c;
		if(sum == 1) {
			//find which one has 1
			if(a == 1) {
				puts("A");
			} else if(b == 1) {
				puts("B");
			}else{
				puts("C");
			}
		}else if(sum == 2) {
			//find which one has 0
			if(a == 0) {
				puts("A");
			} else if(b == 0) {
				puts("B");
			}else{
				puts("C");
			}
		} else{
			puts("*");
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