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

const int maxn = 1e7 + 5;

int bit[maxn];

void update(int idx, int val) {
	for(int i=idx;i<maxn;i+=(i&-i)){
		bit[i] += val;
	}
}

int query(int idx) {
	int ans = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		ans += bit[i];
	}
	return ans;
}

int main(){
	int n,tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(bit, 0, sizeof bit);
		scanf("%d",&n);
		ll ans = 0;
		for(i=1;i<=n;i++){
			int bil;
			scanf("%d",&bil);
			update(bil, 1);
			ans += query(maxn-1) - query(bil);
		}
		printf("%lld\n",ans);
	}
	return 0;
};