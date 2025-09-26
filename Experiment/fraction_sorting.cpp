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

bool cmp(ii a, ii b) {
	return a.first * b.second < a.second * b.first;
}

void solve(){
	int n;
	scanf("%d",&n);
	vii fractions;
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d %d",&a,&b);
		fractions.pb(ii(a, b));
	}

	sort(fractions.begin(), fractions.end(), cmp);

	for(int i=0;i<n;i++){
		ii el = fractions[i];
		printf("%d/%d\n", el.first, el.second);
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