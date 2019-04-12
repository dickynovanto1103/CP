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

const int maxn = 2e5 + 5;

ll dp[maxn];
ll st[4*maxn];

int left(int n){return n<<1;}
int right(int n){return (n<<1) + 1;}

ll query(int node, int l, int r, int i, int j){
	if(l > r){return 0;}
	if(r < i || l > j){return 0;}
	if(i<= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	ll ans1 = query(left(node), l, mid, i, j);
	ll ans2 = query(right(node), mid+1, r, i, j);
	return max(ans1, ans2);
}

void update(int node, int l, int r, int idx, ll val){
	if(r < idx || l > idx){return;}
	if(l == idx && r == idx){st[node] = val; return;}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx, val);
	st[node] = max(st[left(node)], st[right(node)]);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int h[maxn], a[maxn];

	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		ll maks = query(1,1,n,1,h[i]-1);
		// printf("query dari 1 sampe %d\n",h[i]-1);
		ll nilaiSekarang = dp[h[i]];
		if(nilaiSekarang < maks + a[i]){
			nilaiSekarang = maks + a[i];
			// printf("i: %d maks: %lld nilaiSekarang: %lld diupdate di h: %d\n",i,maks,nilaiSekarang, h[i]);
			dp[h[i]] = nilaiSekarang;
			update(1,1,n,h[i], nilaiSekarang);
		}
	}
	printf("%lld\n",*max_element(dp+1, dp+n+1));
	return 0;
};