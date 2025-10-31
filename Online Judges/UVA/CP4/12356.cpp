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
	int s, b;
	while(scanf("%d %d",&s,&b), (s || b)) {
		int next[s+10] = {0}, prev[s+10] = {0};
		fill(next, next + s + 1, -1); fill(prev, prev + s + 1, -1);
		for(int i=1;i<s;i++){
			next[i] = i+1;
		}
		for(int i=s-1;i>=2;i--){
			prev[i] = i-1;
		}

		while(b--){
			int a,b;
			scanf("%d %d",&a,&b);
			if(prev[a] == -1) {
				printf("* ");
			}else{
				printf("%d ", prev[a]);
				next[prev[a]] = next[b];
			}

			if(next[b] == -1) {
				puts("*");
			}else{
				printf("%d\n", next[b]);
				prev[next[b]] = prev[a];
			}
		}

		puts("-");
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