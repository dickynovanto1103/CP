#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	ll a[100];
	int i;
	a[1] = 1; a[2] = 2;
	for(i=3;i<=100;i++){
		a[i] = a[i-1]+a[i-2];
	}
	/*for(i=1;i<=100;i++){
		printf("%lld\n",a[i]);
	}*/
	int n;
	while(scanf("%d",&n),n){
		printf("%lld\n",a[n]);
	}
	return 0;
}