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

const int maxn = 2e4 + 4;

int main(){
	int n,r,i,j;
	long double a[2*maxn];
	int tc = 1;
	while(scanf("%d %d",&n,&r), (n || r)){
		printf("Case %d: ",tc++);
		for(i=0;i<n;i++){
			scanf("%Lf",&a[i]);
		}	

		sort(a,a+n);
		for(i=0;i<n;i++){
			a[i+n] = a[i] + 360.0L;
		}
		ll ans = 1LL*((ll)n*((ll)n-1LL)*((ll)n-2LL))/6LL;
		for(i=0;i<n;i++){
			ll idx = upper_bound(a,a+n+n,a[i] + 180.0L) - a - 1 - i;
			printf("idx: %d\n",idx);
			// cout<<"wew :  "<<idx<<endl;
			// printf("a[%d]: %lf idx: %d\n",i,a[i],idx);
			if(idx > 1)
				ans -= 1LL*idx*(idx-1)/2;
			// printf("ans jd: %lld\n",ans);
		}
		printf("%lld\n",ans<0LL? 0LL : ans);
	}
	return 0;
};