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

int a[200010];
ll pref[200010];
ll maks[200010];

int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		pref[0] = a[0];
		maks[0] = a[0];
		for(i=1;i<n;i++){
			pref[i] = pref[i-1] + a[i];
			maks[i] = max(maks[i-1], pref[i]);
		}
		ll ans = 0;
		ll cur = 0;
		for(i=0;i<n;i++){
			ans = max(ans, cur + maks[i]);
			cur += pref[i];
		}
		printf("%lld\n",ans);
	}

	
	
	return 0;
};