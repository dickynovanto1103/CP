#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n, i,j,k,t;
ll a[200003];

int main(){
	scanf("%d", &n);
	int maxsz = 1;
	int st = 0;
	ll offset;
	for(i=0;i<n;++i)
		scanf("%lld", a+i);
	sort(a, a+n);
	for(i=0;i<n;++i){
		int sztmp;
		ll x = 1;
		ll now = a[i];
		while(now - x >= a[0] || now + x <= a[n-1]){
			sztmp = 1;
			if((now - x) >= a[0])
				sztmp += binary_search(a, a+n, now-x);
			if((now + x) <= a[n-1])
				sztmp += binary_search(a, a+n, now+x);
			if(sztmp > maxsz){
				maxsz = sztmp;
				st = i;
				offset = x;
			}
			x <<= 1;
		}
	}
	ll x = 1;
	ll now = a[st];
	printf("%d\n", maxsz);
	printf("%d ", now);
	if(binary_search(a, a+n, now-offset))
		printf("%lld ", now - offset);
	if(binary_search(a, a+n, offset+now))
		printf("%lld ", now + offset);
	puts("");
	return 0;
}