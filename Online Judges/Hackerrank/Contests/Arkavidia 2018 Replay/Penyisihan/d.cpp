#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000LL
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

const int maxn = 1e5 + 10;
ll arrJawaban[maxn];
ll st[4*maxn];
int n,k;
ll a[maxn];
ll dp[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r) {
	if(l==r) {
		st[node] = arrJawaban[l];
		// printf("arrJawaban[%d]: %d\n",l,arrJawaban[l]);
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		st[node] = min(st[left(node)], st[right(node)]);

		// printf("l: %d mid: %d r: %d st[%d]: %d\n",l,mid,r,node,st[node]);
		// printf("st[%d]: %d st[%d]: %d\n",left(node), st[left(node)], right(node), st[right(node)]);
	}
}

void update(int node, int l, int r, int idx, int val) {
	if(idx < l || idx > r) {return;}
	if(idx==l && idx==r) {
		st[node] = val;
		return;
	}

	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx,val);

	st[node] = min(st[left(node)], st[right(node)]);
}

ll query(int node, int l, int r, int i, int j) {
	if(l > j || r < i) {
		return inf;
	}
	if(i<=l && r<=j) {
		return st[node];
	}
	int mid = (l+r)/2;
	ll ans1 = query(left(node), l, mid, i, j);
	ll ans2 = query(right(node), mid+1, r, i, j);
	// printf("l: %d mid: %d r: %d ans1: %d ans2: %d\n",l,mid,r,ans1,ans2);
	return min(ans1,ans2);
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){

		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++){scanf("%lld",&a[i]);}
		sort(a+1,a+n+1);
		// fill(dp,dp+n+1,-1);

		if(n==k){printf("%lld\n",a[n] - a[1]); continue;}
		if(k==1){printf("0\n"); continue;}

		for(i=n;i>(n-k+1);i--) {
			dp[i] = inf;
			arrJawaban[i] = inf;
			// printf("i: %d\n",i);
		}

		build(1,1,n);
		// printf("query(3,5): %d\n",query(1,1,n,3,5));

		int idx = i;
		for(i=idx;i>=1;i--) {
			ll ans1 = -a[i] + query(1,1,n,i+k, n);
			ll ans2 = min(ans1, a[n] - a[i]);
			// printf("a[%d] - a[%d]: %d\n",n,i,a[n] - a[i]);
			// printf("ans2: %d\n",ans2);
			// printf("i: %d ans1: %d ans2: %d i+k: %d n: %d\n",i,ans1,ans2,i+k,n);
			dp[i] = min(ans1,ans2);
			arrJawaban[i] = dp[i] + a[i-1];
			update(1,1,n,i,arrJawaban[i]);
		}
		printf("%lld\n",dp[1]);
		
	}
	return 0;
};