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

const int maxn = 3e5 + 5;

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	ll pref[maxn];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	pref[0] = a[0];
	for(i=1;i<n;i++){
		pref[i] = pref[i-1] + (ll)a[i];
	}
	ll ans = 0;
	ans = pref[n-1];

	for(i=0;i<(n-1);i++){
		ans += pref[n-1] - pref[i];
		ans += a[i];
	}
	printf("%lld\n",ans);
	return 0;
};