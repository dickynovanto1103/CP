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
	int tc,i,j;
	int a,b,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&k);
		ll selisih = a-b;
		ll bagi2 = k/2LL;
		ll ans = 0;
		ans += selisih*bagi2;
		if(k&1){
			ans += a;
		}
		printf("%lld\n",ans);
	}
	return 0;
};