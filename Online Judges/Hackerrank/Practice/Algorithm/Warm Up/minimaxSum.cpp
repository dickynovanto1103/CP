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
	int i,j;
	ll a[6];
	ll minim = inf, maks = -inf;
	ll sum = 0;
	for(i=0;i<5;i++){scanf("%lld",&a[i]); minim = min(minim,a[i]); maks = max(maks, a[i]); sum+=a[i];}
	printf("%lld %lld\n",sum-maks, sum-minim);
	return 0;
};