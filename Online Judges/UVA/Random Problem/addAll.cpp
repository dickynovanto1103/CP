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

const int maxn = 5010;

int main(){
	int n,i,j;
	int a[maxn];
	while(scanf("%d",&n),n) {
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		ll sum = a[0] + a[1];
		ll sebelum = sum;
		for(i=2;i<n;i++){
			ll ans = sebelum + a[i];
			// printf("ans: %d\n",ans);
			sebelum = ans;
			sum+=ans;
		}
		printf("%lld\n",sum);
	}
	return 0;
};