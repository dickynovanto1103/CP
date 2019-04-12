#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

ii st[4*maxn];
int a[maxn];

void build(int node, int l, int r){
	if(l == r){
		st[node] = ii(a[l], a[l]);
		return;
	}
	int mid = (l+r)/2;
	build(left(node), l, mid);
	build(right(node), mid+1, r);
	st[node] = ii(min(st[left(node)].first, st[right(node)].first), max(st[right(node)].second, st[left(node)].second));
}

ii query(int node, int l, int r, int i, int j){
	if(i > j){return ii(inf,inf);}
	if(r < i || l > j){return ii(inf,inf);}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i, j);
	ii ans2 = query(right(node), mid+1, r, i, j);
	if(ans1 == ii(inf,inf)){return ans2;}
	if(ans2 == ii(inf,inf)){return ans1;}
	ll minim = min(ans1.first, ans2.first);
	ll maks = max(ans1.second, ans2.second);
	return ii(minim, maks);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	int cnt = 0;
	for(i=1;i<=n;i++){
		ii ans1 = query(1,1,n,1,i-1);
		// printf("query dari 1 sampe %d\n",i-1);
		ii ans2 = query(1,1,n,i+1,n);
		if(i == 1){
			ll minimKanan = ans2.first;
			if(minimKanan > a[i]){
				// printf("a[%d]: %d\n",i,a[i]);
				cnt++;
			}
		}else if(i == n){
			ll maksKiri = ans1.second;
			if(maksKiri < a[i]){
				// printf("a[%d]: %d\n",i,a[i]);
				cnt++;
			}
		}else{
			ll minimKanan = ans2.first;
			ll maksKiri = ans1.second;

			if(maksKiri < a[i] && a[i] < minimKanan){
				// printf("a[%d]: %d\n",i,a[i]);
				// printf("maksKiri: %lld minimKanan: %lld\n",maksKiri, minimKanan);
				// printf("%lld %lld\n",ans1.first, ans1.second);
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};