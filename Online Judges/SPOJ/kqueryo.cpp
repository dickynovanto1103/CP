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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 3e4 + 4;

vi st[4*maxn];

int a[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r) {
	debug printf("node: %d %d %d\n",node,l,r);
	if(l == r) {
		st[node].pb(a[l]);
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		merge(st[left(node)].begin(), st[left(node)].end(), st[right(node)].begin(), st[right(node)].end(), back_inserter(st[node]));
	}
}

int query(int node, int l, int r, int i, int j, int k) {
	if(l > j || r < i){return 0;}
	if(i <= l && r <= j){
		return st[node].size() - (upper_bound(st[node].begin(), st[node].end(), k) - st[node].begin());
	}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j, k);
	int ans2 = query(right(node), mid+1, r, i, j, k);
	return ans1 + ans2;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	int q;
	scanf("%d",&q);
	int last = 0;
	for(i=1;i<=q;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a ^= last;
		b ^= last;
		c ^= last;
		a = max(a, 1);
		b = min(b, n);
		int ans;
		if(a > b){
			ans = 0;

		}else{
			ans = query(1,1,n,a,b,c);
		}
		printf("%d\n",ans);
		last = ans;
	}
	return 0;
};