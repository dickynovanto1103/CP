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

const int maxn = 3e5 + 5;
ii st[4*maxn];

int a[maxn];

int left(int n){return n<<1;}
int right(int n){return (n<<1) + 1;}

void build(int node, int l, int r) {
	if(l == r){
		st[node] = ii(a[l], a[l]);
		return;
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		int minim = min(st[left(node)].first, st[right(node)].first);
		int maks = max(st[left(node)].second, st[right(node)].second);
		st[node] = ii(minim, maks);
	}
}

ii query(int node, int l, int r, int i, int j) {
	if(i <= l && r <= j){return st[node];}
	if(r < i || l > j){return ii(-1,-1);}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i, j);
	ii ans2 = query(right(node), mid+1, r, i, j);
	if(ans1 == ii(-1,-1)){return ans2;}
	if(ans2 == ii(-1,-1)){return ans1;}
	int minim = min(ans1.first, ans2.first);
	int maks = max(ans1.second, ans2.second);
	return ii(minim, maks);
}

void selfMin(int &a, int b){
	a = min(a, b);
}

void selfMax(int &a, int b){
	a = max(a, b);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);	
	}
	build(1,1,n);
	vi listIdxAwal;
	int ans[maxn];
	memset(ans, 0, sizeof ans);
	ans[1] = 1;
	listIdxAwal.pb(1);
	int marked[maxn];
	memset(marked, false, sizeof marked);
	marked[1] = true;
	for(i=2;i<=n;i++){
		int maksAns = 1;
		int maksBil = -inf, minBil = inf;
		int idxMin = -1;
		for(j=i;j>=1;j--){
			selfMax(maksBil, a[j]);
			selfMin(minBil, a[j]);
			

			if(marked[j]){
				selfMax(maksAns, ans[j]);
				if(a[j] == minBil && a[i] == maksBil){
					idxMin = j;	
				}
			}
		}
		if(idxMin == -1){
			ans[i] = maksAns + 1;
			marked[i] = true;
		}else{
			ans[i] = ans[idxMin];
			for(j=idxMin+1;j<=i;j++){
				marked[j] = false;
			}
		}
		// printf("ans[%d]: %d\n",i, ans[i]);
	}
	printf("%d\n",ans[n]);

	return 0;
};