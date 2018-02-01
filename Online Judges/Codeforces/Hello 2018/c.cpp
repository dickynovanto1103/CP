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
	int n,i,j;
	ll litre;
	ll a[50];
	scanf("%d %lld",&n,&litre);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n-1;i++){
		a[i+1] = min(a[i+1],2LL*a[i]);
	}
	ll ans = 4e18;
	ll sum = 0;
	ll sisa = litre;
	for(i=n-1;i>=0;i--){
		ll banyak = sisa/(1LL<<i);
		ll harga = banyak*a[i];
		sum+=harga;
		sisa-=(banyak*(1LL<<i));
		ans = min(ans,sum+(sisa>0)*a[i]);
	}
	printf("%lld\n",ans);
	

	return 0;
};