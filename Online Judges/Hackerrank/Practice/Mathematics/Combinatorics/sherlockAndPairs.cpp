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

int cnt[1000001];

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		memset(cnt, 0, sizeof cnt);
		int bil;
		for(i=0;i<n;i++){scanf("%d",&bil); cnt[bil]++;}
		ll ans = 0;
		for(i=1;i<=1000000;i++){
			ll banyak = cnt[i];
			ans += (banyak*(banyak-1));
		}
		printf("%lld\n",ans);
	}
	return 0;
};