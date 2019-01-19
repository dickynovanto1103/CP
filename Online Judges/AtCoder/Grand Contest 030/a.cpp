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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ll a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	ll ans = 0;
	if(a >= c){
		ans = c;
		a -= c;
		c = 0;
		ans += b;

	}else{
		ans = a;
		c -= a;
		a = 0;
		if(b >= c){
			ans += (b + c);	
		}else{
			ans += 2LL*b;
			ans++;
		}
		

	}
	printf("%lld\n",ans);
	
	return 0;
};