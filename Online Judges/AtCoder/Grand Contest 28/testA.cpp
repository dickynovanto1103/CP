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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	ll gcd = __gcd(n,m);
	ll lcm = ((ll)n*(ll)m) / gcd;
	for(i=lcm;;i+=lcm){
		if(i == 6*lcm){break;}
		printf("i: %d\n",i);
		ll selisih1 = i/n;
		ll selisih2 = i/m;
		vi a,b;
		for(j=0;j<n;j++){
			a.pb(j*selisih1);
			printf("%lld ",j*selisih1);
		}
		printf("\n");
		for(j=0;j<n;j++){
			b.pb(j*selisih2);
			printf("%lld ",j*selisih2);
		}
		printf("\n");
		for(j=0;j<n;j++){
			int idx = lower_bound(b.begin(),b.end(), a[j]) - b.begin();
			if(b[idx] == a[j]){
				printf("sama: %lld dan ditemukan di idx: %d %d\n",b[idx], j, idx);
			}
		}
	}
	return 0;
};