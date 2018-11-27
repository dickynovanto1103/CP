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

const int maxBil = 1e6;
const int maxn = 3e5;
int numDiv[maxBil+10];

ll maks[4*maxn], sum[4*maxn];
ll a[maxn];

int left(int n){return n<<1;}
int right(int n){return (n<<1) + 1;}

void build(int node, int l, int r){
	if(l == r){
		sum[node] = a[l];
		maks[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		maks[node] = max(maks[left(node)], maks[right(node)]);
		sum[node] = sum[left(node)] + sum[right(node)];
	}
}

void update(int node, int l, int r, int idx, ll val){
	sum[node] = val;
	maks[node] = val;
	a[l] = val;
}

void updateRange(int node, int l, int r, int i, int j){
	if(r < i || l > j){return ;}
	if(i <= l && r <= j){
		if(maks[node] > 2){
			int mid = (l+r)/2;
			if(l == r){
				update(node, l, r, l, numDiv[a[l]]);
				return;
			}
			updateRange(left(node), l, mid, i, j);
			updateRange(right(node), mid+1,r, i,j);
			sum[node] = sum[left(node)] + sum[right(node)];
			maks[node] = max(maks[left(node)], maks[right(node)]);
		}
		return;
	}
	int mid = (l+r)/2;
	updateRange(left(node), l, mid, i, j);
	updateRange(right(node), mid+1,r, i,j);
	sum[node] = sum[left(node)] + sum[right(node)];
	maks[node] = max(maks[left(node)], maks[right(node)]);
}

ll query(int node, int l, int r, int i, int j){
	if(r < i || l > j){return 0;}
	if(i <= l && r <= j){return sum[node];}
	int mid = (l+r)/2;
	ll sum1 = query(left(node), l,mid, i,j);
	ll sum2 = query(right(node), mid+1, r, i, j);
	return sum1+sum2;
}

int main(){
	int i,j,n,m;
	for(i=1;i<=maxBil;i++){
		for(j=i;j<=maxBil;j+=i){
			numDiv[j]++;
		}
	}
	
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	while(m--){
		int com, l, r;
		scanf("%d %d %d",&com,&l,&r);
		if(com == 1){
			updateRange(1,1,n,l,r);
		}else{
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
	return 0;
};