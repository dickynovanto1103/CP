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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		ll bil;
		ll maks = -inf;
		ll sum = 0;
		for(i=0;i<n;i++){
			scanf("%lld",&bil);
			maks = max(maks, bil);
			sum += bil;
		}
		double ans = maks + (1.0 * (sum - maks) / (n-1));
		printf("%.9lf\n", ans);
	}
	
	return 0;
};