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

int main(){
	ll n,k;
	scanf("%lld %lld",&n,&k);
	ll ans = k/n + (k%n == 0? 0LL: 1LL);
	printf("%lld\n",ans);
	return 0;
};