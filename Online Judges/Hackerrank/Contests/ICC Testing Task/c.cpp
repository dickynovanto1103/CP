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
	ll a[10010];
	int i,j,n;
	a[1] = 1; a[2] = 5;
	ll penambahan = 4;
	for(i=3;i<=10000;i++){
		penambahan+=4;
		a[i] = a[i-1] + penambahan;
	}
	scanf("%d",&n);
	printf("%lld\n",a[n]);

	return 0;
};