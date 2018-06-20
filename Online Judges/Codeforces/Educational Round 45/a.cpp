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
	ll a,b,n,m;
	scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
	if(n%m==0){
		printf("0\n");
	}else{
		ll banyakHancur = n%m;
		ll banyakBikin = m - banyakHancur;

		ll harga1 = banyakHancur*b;
		ll harga2 = banyakBikin*a;

		printf("%lld\n",min(harga2, harga1));
	}
	return 0;
};