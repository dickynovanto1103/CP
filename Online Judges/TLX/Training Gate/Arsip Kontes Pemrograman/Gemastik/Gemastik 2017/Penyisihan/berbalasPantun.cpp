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

const int maxn = 100000;
ll a[maxn], b[maxn];

int main(){
	int i,j;
	ll n;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	ll sum = 0;
	for(i=0;i<n;i++){scanf("%lld",&b[i]); sum+=b[i];}
	ll ans = 0;
	for(i=0;i<n;i++){
		ans += (a[i]*n);
	}
	ans+=(sum*n);
	printf("%lld\n",ans);
	return 0;
};