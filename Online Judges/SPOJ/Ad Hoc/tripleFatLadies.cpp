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

bool tigaBelakang(ll a){
	for(int i=0;i<3;i++){
		ll bil = a%10;
		if(bil!=8){return false;}
		a/=10;
	}
	return true;
}

int main() {
	ll i;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&i);
		printf("%lld\n",192LL+((i-1LL)*250LL));
	}
	
	return 0;
}