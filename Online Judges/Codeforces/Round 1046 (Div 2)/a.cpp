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

int ceiling(int a, int b) {
	return (a + b - 1) / b;
}

bool isValid(int a, int b) {
	if(a < b) {
		swap(a, b);
	}

	int val = ceiling(a, b + 1);
	return val < 3;
}

void solve(){
	int a, b, c, d;
	scanf("%d %d %d %d",&a,&b,&c,&d);

	if(!isValid(a, b)) {
		puts("NO");
		return;
	}

	c -= a;
	d -= b;
	if(!isValid(c, d)) {
		puts("NO");
		return;
	}
	puts("YES");
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};