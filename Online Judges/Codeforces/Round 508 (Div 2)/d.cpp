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

const int maxn = 5e5 + 5;

ll a[maxn];
ll pref[maxn], suff[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}

	if(n == 1){
		printf("%lld\n",a[1]);
		return 0;
	}else if(n==2){
		printf("%lld\n",max(a[1] - a[2], a[2] - a[1]));
		return 0;
	}

	for(i=1;i<=n;i++){
		pref[i] = pref[i-1] + abs(a[i]);
	}
	for(i=n;i>=1;i--){
		suff[i] = suff[i+1] + abs(a[i]);
	}

	ll ans = -inf;

	for(i=1;i<n;i++){
		ll selisih = a[i] - a[i+1];
		if(selisih <= 0){
			ans = max(ans, pref[i-1] + suff[i+2] + abs(selisih));
		}
		selisih = a[i+1] - a[i];
		if(selisih <= 0){
			ans = max(ans, pref[i-1] + suff[i+2] + abs(selisih));	
		}
	}
	printf("%lld\n",ans);

	return 0;
};