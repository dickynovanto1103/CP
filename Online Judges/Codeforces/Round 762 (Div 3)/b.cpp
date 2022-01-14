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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	vi a;

	set<ll> s;
	s.insert(1);
	for(i=2;i<100000;i++){
		// ll kuadrat = (ll)i*i;
		// ll tiga = (ll)i * i * i;
		// if(kuadrat == tiga) {

		// }
		s.insert((ll)i*i);
		s.insert((ll)i*i*i);
	}
	set<ll>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		a.pb(*it);
	}
	// printf("size: %d\n", a.size());

	scanf("%d",&tc);
	while(tc--){
		ll n;
		scanf("%lld",&n);
		int idx = upper_bound(a.begin(), a.end(), n) - a.begin();
		printf("%d\n", idx);
	}
	
	
	return 0;
};