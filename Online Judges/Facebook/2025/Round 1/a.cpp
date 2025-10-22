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
	int a[n+1];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	int maks = 0;
	for(int i=0;i<n-1;i++){
		maks = max(maks, abs(a[i] - a[i+1]));
	}
	printf("%d\n", maks);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	int tt =1;
	while(tc--){
		printf("Case #%d: ", tt++);
		solve();
	}

	return 0;
};