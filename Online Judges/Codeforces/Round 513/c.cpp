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
typedef vector<ll> vi;
typedef pair<ll,int> ii;
typedef vector<ii> vii;

const int maxn = 2011;

ll a[maxn], b[maxn];
ll pref1[maxn], pref2[maxn];
ii v1[maxn*maxn], v2[maxn*maxn];

int st[maxn*maxn*4];
int left(int n){return 2*n;}
int right(int n){return 2*n+1;}
void build(int node, int l, int r){
	if(l == r){
		st[node] = v2[l].second;
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		st[node] = max(st[left(node)], st[right(node)]);
	}
}

int query(int node, int l, int r, int i, int j){
	// printf("l: %d r: %d i: %d j: %d\n",l,r,i,j);
	if(r < i || l > j){
		return -10;
	}
	if(i <=l && r <= j){
		// printf("yang direturn: %d\n",st[node]);
		return st[node];
	}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i,j);
	int ans2 = query(right(node), mid+1, r, i, j);
	// printf("mid: %d ans1: %d ans2: %d\n",mid,ans1,ans2);
	return max(ans1,ans2);
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pref1[i] += pref1[i-1]; pref1[i] += a[i];
	}
	for(i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		pref2[i] += pref2[i-1]; pref2[i] += b[i];
	}
	ll x;
	scanf("%lld",&x);
	int ukuran1 = 0, ukuran2 = 1;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			ll jumlah = pref1[j] - pref1[i-1];
			v1[ukuran1] = ii(jumlah,(j-i+1));
			ukuran1++;
			// printf("yang dipush: %lld %d\n",jumlah, (j-i+1));
		}
	}
	for(i=1;i<=m;i++){
		for(j=i;j<=m;j++){
			ll jumlah = pref2[j] - pref2[i-1];
			v2[ukuran2] = ii(jumlah,(j-i+1));
			ukuran2++;
			// printf("kedua yang dipush: %lld %d\n",jumlah, (j-i+1));
		}
	}
	sort(v1, v1+ukuran1);
	sort(v2, v2+ukuran2);
	// int ukuran1 = v1.size(), ukuran2 = v2.size();
	vi listBil;
	for(i=1;i<ukuran2;i++){
		listBil.pb(v2[i].first);
		// printf("%lld %d\n",v2[i].first,v2[i].second);
	}
	build(1,1,ukuran2-1);
	int ans = 0;
	for(i=0;i<ukuran1;i++){
		ll bil1 = v1[i].first;
		ll diminta = x / bil1;

		int banyakRow = v1[i].second;
		// printf("bil1: %lld diminta: %lld banyakRow: %d\n",bil1,diminta,banyakRow);
		int idx = upper_bound(listBil.begin(), listBil.end(), diminta) - listBil.begin();
		int maks = query(1,1,ukuran2-1,1,idx);
		// printf("idx: %d maks: %d\n",idx,maks);
		ans = max(ans, maks*banyakRow);
		// printf("ans jd: %d\n",ans);
	}
	
	printf("%d\n",ans);
	return 0;
};