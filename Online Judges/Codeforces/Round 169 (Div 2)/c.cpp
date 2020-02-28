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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j,q;
	scanf("%d %d",&n,&q);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int cnt[maxn];
	memset(cnt, 0, sizeof cnt);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		l--; r--;
		cnt[l]++; cnt[r+1]--;
	}
	for(i=0;i<n;i++){
		if(i){
			cnt[i] += cnt[i-1];
		}
	}
	sort(cnt, cnt+n);
	sort(a,a+n);
	ll ans = 0;
	for(i=0;i<n;i++){
		ans += (ll)a[i]*cnt[i];
	}
	printf("%lld\n",ans);
	return 0;
};