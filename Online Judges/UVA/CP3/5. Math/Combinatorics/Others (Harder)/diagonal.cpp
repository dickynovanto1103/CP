#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


const ll maxn = 1e15;
ll a[45623800];

int main() {
	ll cnt = 2;
	a[3] = 0; a[4] = 2;
	int i = 4;
	//printf("maxn: %lld\n",maxn);
	while(true){
		i++; cnt++;
		a[i] = a[i-1]+cnt;
		//printf("a[%d]: %lld\n",i,a[i]);
		if(a[i]>=maxn){break;}
	}
	int idx = i;
	//printf("idx: %d a: %lld\n",idx,a[idx]);
	ll n;
	int tc = 1;
	while(scanf("%lld",&n),n){
		printf("Case %d: ",tc++);
		int indeks = lower_bound(a,a+idx,n) - a;
		printf("%d\n",indeks);
	}
	return 0;
}