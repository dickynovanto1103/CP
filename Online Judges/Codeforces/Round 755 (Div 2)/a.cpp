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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int a,b;
		scanf("%d %d",&a,&b);
		int sum = a + b;
		ll kali = (ll)a * b;
		ll koefX = (ll)b * sum - kali;
		ll koefY = (ll)a * sum - kali;
		ll x = -koefY;
		ll y = koefX;
		printf("%lld %lld\n", x, y);
	}
	
	return 0;
};