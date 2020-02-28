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
typedef pair<ll,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m,i,j,k;
	vii listAns;
	ll ans = 0;
	int a[300001];
	scanf("%d %d %d",&n,&m,&k);
	ll bil = 0;
	int cnt = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		bil += a[i];
		if(bil < 0){
			bil = 0;
			cnt = 0;
		}else{
			cnt++;
			listAns.pb(ii(bil, cnt));
			// printf("dipush: %lld %d\n",bil, cnt);
		}
	}
	for(i=0;i<listAns.size();i++){
		ll first = listAns[i].first;
		ll banyak = listAns[i].second;

		ans = max(ans, first - (ll)k*(ll)((banyak+m-1)/m));
	}
	printf("%lld\n",ans);
	return 0;
};