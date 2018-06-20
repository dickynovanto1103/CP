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
	vi a;
	ll bil;
	while(scanf("%lld",&bil)!=EOF) {
		a.pb(bil);
	}
	for(int i=a.size()-1;i>=0;i--){
		bil = a[i];
		printf("%.5lf\n",sqrt(bil));
	}
	return 0;
};