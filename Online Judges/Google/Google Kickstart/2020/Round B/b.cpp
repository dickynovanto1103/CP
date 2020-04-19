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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll a[1010];

bool can(ll mid, int n, ll d) {
	int i,j;
	ll now = mid;
	for(i=0;i<n;i++){
		ll pengali = (now + a[i]-1LL)/a[i];
		// printf("a[%d]: %lld pengali: %lld\n",i, a[i], pengali);
		ll harusnya = a[i] * pengali;

		ll timenow = harusnya;
		// printf("now: %lld timenow: %lld\n",now, timenow);
		now = timenow;
		// printf("now jd: %lld\n",now);
		if(now > d){return false;}
	}
	if(now > d){return false;}
	return true;
}

int main(){
	int tc,i,j,n;
	ll d;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %lld",&n,&d);
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		ll kiri = 1, kanan = d, mid, ans;
		while(kiri <= kanan) {
			mid = (kiri+kanan)/2LL;
			if(can(mid,n, d)){
				ans = mid;
				kiri = mid+1;
			}else{
				kanan = mid-1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
};