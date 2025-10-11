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
	int c, addF;
	scanf("%d %d",&c,&addF);
	double f = (9.0 * c / 5.0) + 32.0;
	// printf("fahrenheit: %lf\n", f);
	double newF = f + addF;
	double newC = (newF - 32.0) * 5.0 / 9.0;
	printf("%.2lf\n", newC);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ", tt);
		solve();
	}

	return 0;
};