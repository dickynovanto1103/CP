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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	ll minim = inf, maks = 0, sum = 0;
	for(i=0;i<n;i++){
		ll bil;
		scanf("%lld",&bil);
		minim = min(minim, bil); maks = max(maks, bil); sum += bil;
	}
	for(i=0;i<4;i++){
		if(i == minim || i == maks || i == sum){continue;}
		printf("%d\n",i); break;
	}
	// printf("%lld %lld %lld\n",minim, maks, sum);
	return 0;
};