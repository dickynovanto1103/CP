#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	ll a,b,x,y;
	scanf("%lld %lld %lld %lld",&a,&b,&x,&y);
	while(x<=y){
		printf("%lld\n",x);
		x*=a; x+=b;
	}
	return 0;
}