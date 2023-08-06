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

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int w,d,h;
		scanf("%d %d %d",&w,&d,&h);
		int a,b,f,g;
		scanf("%d %d %d %d",&a,&b,&f,&g);
		int ans1 = h + min(a + f, (w-a) + (w - f)) + abs(b - g);
		int ans2 = h + abs(a - f) + min(b + g, (d - b) + (d - g));

		printf("%d\n", min(ans1, ans2));
	}
	
	return 0;
};