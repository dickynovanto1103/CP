#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll x,y,d;
void gcdExtended(ll a, ll b){
	if(b==0){d = a; x = 1; y=0; return;}
	gcdExtended(b,a%b);
	ll x1 = y;
	ll y1 = x-(a/b)*y;
	x = x1;
	y = y1;
}

int main() {
	ll a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF){
		//if(a>b){swap(a,b);}
		gcdExtended(a,b);
		
		printf("%lld %lld %lld\n",x,y,d);
	}
	return 0;
}