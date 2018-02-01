#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	ll a,b,c,d;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		ll jumlah = (c-a) + (d-b);
		printf("%lld\n",jumlah);	
	}
	
	return 0;
}