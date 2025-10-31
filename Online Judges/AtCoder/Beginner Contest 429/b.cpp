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

int a[101];

void solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	int sum = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}

	for(int i=0;i<n;i++){
		if(sum - a[i] == m) {
			puts("Yes");
			return;
		}
	}

	puts("No");
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};