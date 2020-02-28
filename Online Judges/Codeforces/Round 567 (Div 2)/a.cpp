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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ll x,y,z;
	scanf("%lld %lld %lld",&x,&y,&z);
	ll rem1 = x%z, rem2 = y%z;
	ll sum = x/z + y/z;
	if(rem1 + rem2 >=z) {
		ll maks = max(rem1, rem2);
		sum++;
		ll ans2 = z - maks;
		printf("%lld %lld\n",sum, ans2);
	}else{
		printf("%lld 0\n",sum);
	}
	return 0;
};