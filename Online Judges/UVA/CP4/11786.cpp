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
	char s[10001];
	while(scanf("%s", s) != EOF) {
		int len = strlen(s);
		map<int, int> depthIdx;
		int depth = 0;
		int ans = 0;
		for(int i=0;i<len;i++){
			if(s[i] == '\\') {
				depthIdx[--depth] = i;
			}else if(s[i] == '/') {
				//find the corresponding depthIdx
				if(depthIdx.find(depth) == depthIdx.end()) {
					//ignore, since not found
				}else{
					int idxPair = depthIdx[depth++];
					ans += (i - idxPair);
				}
			}
		}

		printf("%d\n",ans);
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};