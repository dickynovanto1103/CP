#include <bits/stdc++.h>

using namespace std;
#define inf 4000000000000000000LL
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

const int maxn = 2e5 + 5;



int main(){
	int n,i,j;
	ll x[maxn], y[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld %lld",&x[i],&y[i]);
	}

	ll ans = inf;
	for(i=0;i<(n-2);i++){
		ll area = (x[i]*y[i+1] + x[i+1]*y[i+2] + x[i+2]*y[i]) - (x[i+1]*y[i] + x[i+2]*y[i+1] + x[i]*y[i+2]);
		ans = min(ans, area);
		// printf("i: %d ans: %lld\n",i,ans);
	}

	ll a[5], b[5];
	a[0] = x[n-2], b[0] = y[n-2];
	a[1] = x[n-1], b[1] = y[n-1];
	a[2] = x[0], b[2] = y[0];
	i = 0;
	ll area = (a[i]*b[i+1] + a[i+1]*b[i+2] + a[i+2]*b[i]) - (a[i+1]*b[i] + a[i+2]*b[i+1] + a[i]*b[i+2]);
	ans = min(ans, area);
	// printf("ans: %lld\n",ans);

	a[0] = x[n-1], b[0] = y[n-1];
	a[1] = x[0], b[1] = y[0];
	a[2] = x[1], b[2] = y[1];
	i = 0;
	area = (a[i]*b[i+1] + a[i+1]*b[i+2] + a[i+2]*b[i]) - (a[i+1]*b[i] + a[i+2]*b[i+1] + a[i]*b[i+2]);
	ans = min(ans, area);
	// printf("ans: %lld\n",ans);

	printf("%lld\n",ans);


	return 0;
};