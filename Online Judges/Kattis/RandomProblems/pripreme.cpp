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

const int maxn = 3e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	ll tot = 0;
	ll maks = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		tot += (ll)a[i];
		maks = max(maks, (ll)a[i]);
	}
	ll sisa = tot - maks;
	if(sisa < maks){
		tot += (maks - sisa);
	}
	printf("%lld\n",tot);
	
	return 0;
};