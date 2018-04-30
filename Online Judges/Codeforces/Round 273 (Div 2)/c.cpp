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
	ll a[3];
	scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
	int minim = 2*inf;
	sort(a, a+3);
	if((a[0] + a[1])*2LL >= a[2]){
		ll sum = a[0] + a[1] + a[2];
		printf("%lld\n",sum/3LL);
	}else{
		printf("%lld\n",a[0] + a[1]);
	}

	return 0;
};