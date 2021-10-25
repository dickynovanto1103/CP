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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		vi a(n), b(n), ca(n+1), cb(n+1);
		for(i=0;i<n;i++){
			scanf("%d %d",&a[i], &b[i]);
			ca[a[i]]++; cb[b[i]]++;
		}
		ll ans = 1LL * n * (n-1) * (n-2) / 6;
		for(i=0;i<n;i++){
			ans -= (ca[a[i]] - 1) * 1LL * (cb[b[i]] - 1);
		}
		printf("%lld\n", ans);
	}
	
	return 0;
};