#include <bits/stdc++.h>

using namespace std;
#define inf 2000000005
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

const int numDimension = 2;

ii st[1<<numDimension][4LL*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

ii query(int node, int l, int r, int i, int j, int idxST) {
	if(l > j || i > r){return ii(-inf,inf);}
	if(i <= l && r <= j){return st[idxST][node];}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i,j,idxST);
	ii ans2 = query(right(node), mid+1, r, i, j, idxST);
	int maks = max(ans1.first, ans2.first);
	int minim = min(ans1.second, ans2.second);

	return ii(maks, minim);
}

void update(int node, int l, int r, int idx, int val, int idxST){
	if(l > idx || r < idx){return;}
	if(l == idx && r == idx){
		st[idxST][node] = ii(val, val);
		return;	
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val, idxST);
	update(right(node), mid+1, r, idx, val, idxST);
	ii kiri = st[idxST][left(node)];
	ii kanan = st[idxST][right(node)];
	st[idxST][node] = ii(max(kiri.first, kanan.first), min(kiri.second, kanan.second));
}

int a[numDimension];
int n;
void updateArrayInSegtree(int idx) {
	int j,k;
	for(j=0;j<(1<<numDimension);j++){
		int sum = 0;
		for(k=0;k<numDimension;k++){
			if(j & (1<<k)){
				sum += -a[k];
			}else{
				sum += a[k];
			}
		}
		// printf("diupdate di idx: %d sum: %d stIdx: %d\n",idx+1, sum, j);
		update(1,1,n,idx+1,sum,j);
		
	}	
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		
		for(j=0;j<numDimension;j++){
			scanf("%d",&a[j]);
		}
		updateArrayInSegtree(i);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		// printf("q: %d\n",q);
		char com;
		int idx;
		scanf("\n%c",&com);
		if(com == 'U'){
			scanf("%d",&idx);
			// printf("idx: %d\n",idx);
			for(i=0;i<numDimension;i++){
				scanf("%d",&a[i]);
				// printf("val[%d]: %d\n",i,val[i]);
			}	
			updateArrayInSegtree(idx);
		}else{
			int l,r;
			scanf("%d %d",&l,&r);
			// printf("l: %d r: %d\n",l,r);
			ll ans = 0;
			for(i=0;i<1<<numDimension;i++){
				ii hasil = query(1,1,n,l+1,r+1,i);
				ans = max(ans, hasil.first - hasil.second);
			}
			printf("%lld\n",ans);
		}
		
		// printf("com: %c idx: %d\n",com,idx);
	}
	// printf("halo\n");
	return 0;
};