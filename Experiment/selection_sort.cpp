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
	vi v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}

	for(int i=0;i<n;i++){
		int minim = v[i];
		int minimIdx = -1;
		for(int j=i+1;j<n;j++){
			if(minim > v[j]) {
				minim = v[j];
				minimIdx = j;
			}
		}

		if(minimIdx != -1) {
			swap(v[i], v[minimIdx]);
		}
	}

	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}
	puts("");
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};