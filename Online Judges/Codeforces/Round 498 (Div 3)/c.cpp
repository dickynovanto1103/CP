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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	ll a[maxn];
	ll pref[maxn];
	ll suff[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	pref[0] = a[0];
	for(i=1;i<n;i++){
		pref[i] = pref[i-1] + a[i];
	}
	ll total = a[n-1];
	vi listSuff;
	listSuff.pb(total);
	for(i=n-2;i>=0;i--){
		total+=a[i];
		listSuff.pb(total);
	}

	ll maks = 0;
	for(i=0;i<n;i++){
		ll cari = pref[i];
		listSuff.pop_back();
		if(binary_search(listSuff.begin(), listSuff.end(), cari)){
			maks = cari;
		}
	}
	printf("%lld\n",maks);
	return 0;
};