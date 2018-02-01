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
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		ll ans = 0;
		scanf("%d",&n);
		ans = 45*100 + 90*25 - 45*25;
		n-=4;
		for(i=0;i<n;i++){
			ans = ans*10;
			ans%=9973;
		}
		printf("%lld\n",ans);
	}
	return 0;
};