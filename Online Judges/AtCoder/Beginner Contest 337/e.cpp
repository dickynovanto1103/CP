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

void printNumFriends(int n) {
	printf("%d\n", n);
	fflush(stdout);
}

bool bad[101];

vector<vector<int>> allocations;

void processAnswer(int numBottle) {
	string s;
	cin>>s;
	vi idxBad;
	for(int i=0;i<s.size();i++){
		if(s[i] == '1'){
			idxBad.pb(i);
		}else{
			for(int j=0;j<allocations[i].size();j++){
				bad[allocations[i][j]] = false;
			}
		}
	}

	if(idxBad.size() == 1) {
		for(int i=1;i<=numBottle;i++){
			if(bad[i]) {
				printf("%d\n", i);
				fflush(stdout);
				break;
			}
		}
	}else if(idxBad.size() > 1){
		assert(idxBad.size() == 2);
		vi alloc = allocations[idxBad[0]];
		assert(alloc.size() == 2);
		
		printf("%d\n", alloc[1]);
		fflush(stdout);
	}else {
		printf("%d\n", numBottle);
		fflush(stdout);
	}

}

void printAllocs() {
	for(int i=0;i<allocations.size();i++){
		printf("%d", allocations[i].size());
		for(int j=0;j<allocations[i].size();j++){
			printf(" %d", allocations[i][j]);
		}
		printf("\n");
		fflush(stdout);
	}
}

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {
		if(n == 2) {
			printNumFriends(1);
			allocations.pb({1});
			printAllocs();
			processAnswer(n);
		}else if(n == 3) {
			printNumFriends(2);
			vector<int> a = {1};
			vector<int> b = {2};
			allocations.pb(a);
			allocations.pb(b);

			printAllocs();
			processAnswer(n);
		}else{
			printNumFriends(n-2);
			for(int i=1;i<=n-2;i++){
				allocations.pb({i, i+1});
			}
			printAllocs();
			processAnswer(n);
		}
	}
	
}

int main(){
	memset(bad, true, sizeof bad);
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};