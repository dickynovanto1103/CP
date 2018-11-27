#include <bits/stdc++.h>

using namespace std;
#define inf 10000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int left(int n){return (n<<1);}
int right(int n){return (n<<1) + 1;}
//ll a[100010];
ll minim[4*maxn], maks[4*maxn];
ll a[maxn];
void build(int node, int l, int r){
	if(l==r){
		minim[node] = a[l];
		maks[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		minim[node] = min(minim[left(node)], minim[right(node)]);
		maks[node] = max(maks[left(node)], maks[right(node)]);
	}
}

void update(int node, int l, int r, int i, int j, ll val){
	if(l > j || r<i){return;}
	if(i<=l && r<=j){
		minim[node] += val;
		maks[node] += val;k
		return;
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, i,j,val);
	update(right(node), mid+1, r, i, j, val);
	minim[node] = min(minim[left(node)], minim[right(node)]);
	maks[node] = max(maks[left(node)], maks[right(node)]);
}

ll query(int node, int l, int r, int i, int j, int isMinim){
	if(l > j || r < i){
		if(isMinim){return inf;}
		else{return -inf;}
	}
	if(i<=l && r<=j){
		if(isMinim){return minim[node];}
		else{return maks[node];}
	}
	int mid = (l+r)/2;
	ll ans1 = query(left(node), l, mid, i, j, isMinim);
	ll ans2 = query(right(node), mid+1, r, i,j, isMinim);
	if(isMinim){
		return min(ans1,ans2);
	}else{
		return max(ans1,ans2);
	}
}

int main() {
	int n,i;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		ll tinggi;
		scanf("%lld",&tinggi);
		a[i] = tinggi;
		
	}
	build(1,1,n);

	int q;
	scanf("%d",&q);
	while(q--){
		int com;
		scanf("%d",&com);
		if(com==1){
			int a,b;
			ll plus;
			scanf("%d %d %lld",&a,&b,&plus);
			// printf("a: %d b: %d plus: %lld\n",a,b,plus);
			update(1,1,n,a,b,plus);
			// printf("sekarang %lld %lld\n",st.queryMin(1,1,n,i,i), st.queryMax(1,1,n,i,i));
		}else{
			int a,b;
			scanf("%d %d",&a,&b);
			ll minim = query(1,1,n,a,b,1);
			ll maks = query(1,1,n,a,b,0);
			// printf("minim: %lld maks: %lld\n",minim,maks);
			printf("%lld\n",maks-minim);
		}
	}
	
	return 0;
}