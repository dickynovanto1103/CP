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

int totAllowed = 0;

void solve(){
	double l, w, d, weight;
	scanf("%lf %lf %lf %lf",&l,&w,&d,&weight);
	int ans = 0;
	if(((l <= 56 && w <= 45 && d <= 25) || (l + w + d) <= 125) && weight <= 7) {
		ans = 1;
	}
	

	totAllowed += ans;
	printf("%d\n",ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
	printf("%d\n", totAllowed);

	return 0;
};