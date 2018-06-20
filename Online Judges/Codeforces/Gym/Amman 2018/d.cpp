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
	ll n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&m);
		//hitung horizontal
		ll hasilBagi = m/2;
		ll maksBagi = hasilBagi;
		if(m%2==1){
			maksBagi++;
		}
		n++;
		ll ans = 0;
		if(n%2==1){
			ll maksBagian = n/2 + 1;
			ans+=(maksBagian*hasilBagi);
			ans+=((n/2LL)*maksBagi);
		}else{
			ans+=((n/2LL)*hasilBagi);
			ans+=((n/2LL)*maksBagi);
		}
		ll ans1 = ans;

		//hitung vertical
		ll ans2 = 0;
		n--;
		m++;
		hasilBagi = m/2;
		maksBagi = hasilBagi;
		if(m%2==1){
			maksBagi++;
		}

		ans = 0;
		if(n%2==1){
			ll maksBagian = n/2 + 1;
			ans+=(maksBagian*hasilBagi);
			ans+=((n/2LL)*maksBagi);
		}else{
			ans+=((n/2LL)*hasilBagi);
			ans+=((n/2LL)*maksBagi);
		}

		ans2 = ans;

		printf("%lld\n",min(ans1,ans2));
	}
	return 0;
};