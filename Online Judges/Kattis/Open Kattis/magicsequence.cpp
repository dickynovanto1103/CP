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

ll v[1000001];

void solve(){
	int n;
	int a, b, c;
	int x, y;
	scanf("%d",&n);
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d",&x,&y);
	v[0] = a;
	for(int i=1;i<n;i++){
		v[i] = ((v[i-1] * (ll)b) % c + a) % c;
	}

	sort(v, v+n);
	ll hash = 0;
	for(int i=0;i<n;i++){
		hash = ((hash * (ll)x) % y + v[i]) % y;
	}
	printf("%lld\n", hash);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};