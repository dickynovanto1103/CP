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

const int maxn = 1e5 + 5;
ll a[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	int batas = 100000;
	if(n > 32){
		batas = 2;
	}
	ll ans = (ll)inf*inf;
	for(int c = 1;c < batas;c++){
		ll bil = 1;
		ll tot = 0;
		for(i=0;i<n;i++){
			tot += abs(bil - a[i]);
			bil *= (ll)c;
			if(bil > 100LL*inf && i < (n-1)) {
				break;
			}
		}
		if(i == n){
			if(ans > tot) {
				ans = tot;
				// printf("tot: %lld ans: %lld c: %d\n",tot, ans, c);
				// printf("bil akhir: %lld\n",bil);
			}
			
		}
	}
	printf("%lld\n",ans);
	
	
	return 0;
};