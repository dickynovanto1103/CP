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

int findMaxBit(ll bil) {
	int ans = 0;
	for(int i=0;i<=32;i++){
		if((1LL<<i) & bil){
			ans = max(ans, i);
		}
	}
	return ans+1;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	ll a[100001];
	while(tc--){
		scanf("%d",&n);

		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		int maks = 0;
		for(i=1;i<n;i++){
			if(a[i] < a[i-1]){
				int selisih = a[i-1] - a[i];
				maks = max(maks, findMaxBit(selisih));
				a[i] = a[i-1];
			}
		}
		printf("%d\n",maks);
	}
	return 0;
};