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
typedef pair<int,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5;
int cnt[maxn+4];

ll ans[maxn+4];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		cnt[bil]++;
	}
	ans[0] = 0;
	ans[1] = cnt[1];
	for(i=2;i<=maxn;i++){
		ans[i] = max(ans[i-1], ans[i-2] + (ll)cnt[i]*(ll)i);
	}
	printf("%lld\n",ans[maxn]);
	
	return 0;
};