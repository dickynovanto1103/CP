#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
ll a[500002];
ll ri[500002];
ll spt[500002][21];
set<ll> s;

void preprocess(){
	memset(spt, 0, sizeof spt);
	for(int i=n-1;i>=0;--i){
		spt[i][0] = a[i];
		for(int j=1;j<21;++j){
			if(i + (1<<(j-1)) >= n)
				spt[i][j] =  ri[i];
			else
				spt[i][j] = __gcd(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
		}
	}
}

int getnext(int idx, ll val){
	for(int i=0;idx < n && i<21;++i)
		if(spt[idx][i]  % val == 0)
			idx += 1 << i;
		else
			break;
	return idx;
}


int main(){
	scanf("%d", &n);
	for(i=0;i<n;++i)
		scanf("%lld", a+i);
	ri[n] = 0;
	for(i=n-1;i>=0;--i){
		ri[i] = __gcd(ri[i+1], a[i]);
	}
	preprocess();
	for(i=0;i<n;++i){
		ll now = 0;
		for(j=i;j<n;j = getnext(j, now)){
			now = __gcd(a[j], now);
			s.insert(now);
			if(ri[j+1] % now == 0)
				break;
		}
	}
	printf("%d\n", (int)s.size());
	return 0;
}