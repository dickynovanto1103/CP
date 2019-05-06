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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	ll h;
	int i,j,n;
	scanf("%lld %d",&h,&n);
	ll pref[maxn];

	ll temp = h;
	ll a[maxn];
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		temp += a[i];
		pref[i] = a[i];
		if(i){pref[i] += pref[i-1];}
		if(temp<=0){printf("%d\n",i+1); return 0;}
	}
	ll delta = h - temp;
	// printf("delta: %lld\n",delta);
	if(delta <= 0){printf("-1\n");}
	else{
		ll ans = 1e18;
		for(i=0;i<n;i++){
			temp = h;
			temp += pref[i];
			ll iterasi = (temp+delta-1) / delta;
			ans = min(ans, iterasi*(ll)n + (i+1));
		}
		printf("%lld\n",ans);
		// ll iterasi = h / delta;
		// ll sisa = h%delta;
		// ll ans = iterasi * n;
		// if(sisa == 0){printf("%lld\n",ans);}
		// else{
		// 	for(i=0;i<n;i++){
		// 		sisa += a[i];
		// 		if(sisa <= 0){ans += (i+1); printf("%lld\n",ans); return 0;}
		// 	}
		// }
		
	}
	return 0;
};