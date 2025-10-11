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
	int l,d,h,v;
	scanf("%d %d %d %d",&l,&d,&h,&v);
	//g = 9810 mm/s^2...so to find how many second = sqrt(h / 9810)
	// the idea above is wrong...
	// the formula is d = v0*t + 1/2 * a * t^2...so with v0 = 0...so d = 1/2 a * t^2 = t = sqrt(2 * d / a) = sqrt (2*h/g)
	double duration = sqrt(2 * h / 9810.0);
	double dist = duration * v;
	// printf("duration: %lf, dist: %lf, l: %d, d: %d, h: %d, v: %d\n", duration, dist, l, d, h, v);
	if(dist < d - 500 || dist > (d + l + 500)) {
		puts("FLOOR");
	}else if(((d - 500) <= dist && dist <= (d + 500)) || ((d + l - 500) <= dist && dist <= (d + l + 500))) {
		puts("EDGE");
	}else{
		puts("POOL");
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