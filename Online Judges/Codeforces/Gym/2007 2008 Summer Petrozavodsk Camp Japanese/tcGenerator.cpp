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
	srand(time(NULL));
	int i,j;
	for(i=0;i<100;i++){
		ll a, b, c, d;
		a = rand() % (1LL<<31LL);
		b = rand()% (1LL<<31LL);
		c = rand()% (1LL<<31LL);
		d = rand()% (1LL<<31LL);
		printf("%lld %lld %lld %lld\n",a,b,c,d);
	}
	return 0;
};