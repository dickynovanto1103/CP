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
	ll a,b;
	scanf("%lld %lld",&a,&b);
	ll ans = 0;
	while(true){
		ll bagi = a/b;
		ans += bagi;
		a -= (b*bagi);
		if(a == 0){break;}
		swap(a,b);
	}
	
	printf("%lld\n",ans);
	return 0;
};