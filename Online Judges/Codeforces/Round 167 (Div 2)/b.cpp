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

const int maxn = 1e5 + 5;;


int main(){
	int n,i,j;
	
	ll cnt[33];
	memset(cnt, 0, sizeof cnt);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		int ans = __builtin_popcount(bil);
		// printf("bil: %d ans: %d\n",bil,ans);
		// printf("bil: %d ans: %d\n",bil,ans);
		cnt[ans]++;
	}
	ll ans = 0;
	for(i=0;i<33;i++){
		ans += (cnt[i]*(cnt[i]-1LL))/2LL;
	}
	printf("%lld\n",ans);

	return 0;
};