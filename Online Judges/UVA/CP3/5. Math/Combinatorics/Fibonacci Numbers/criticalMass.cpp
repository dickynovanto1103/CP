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

int main() {
	ll a[50];
	a[0] = 0; a[1] = 0; a[2] = 1; a[3] = 3;
	int i;
	for(i=4;i<40;i++){
		a[i] = 3*a[i-1] - a[i-2] - a[i-3] - 2*a[i-4];
	}
	/*for(i=0;i<40;i++){
		printf("%lld\n",a[i]);
	}*/
	int idx;
	while(scanf("%d",&idx),idx){
		printf("%lld\n",a[idx-1]);
	}
	return 0;
}