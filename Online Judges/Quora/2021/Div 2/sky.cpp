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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n;
const int maxn = 3e5 + 5;
const int k = 19;
int sparse[maxn][20];
int st[4*maxn];
int a[maxn];
void preprocess(){
	int i,j;
	for(i=0;i<n;i++){
		sparse[i][0] = a[i];
	}
	// printf("k: %d\n",k);
	// printf("n: %d\n",n);
	for(j=1;j<=k;j++){
		for(i=0;i<n;i++){
			int idxSelanjutnya = i + (1<<(j-1));
			// printf("i: %d j: %d\n",i,j);
 
			if(idxSelanjutnya >= n){break;}
			// printf("i: %d j: %d idxSelanjutnya: %d\n",i,j,idxSelanjutnya);
			// if(j==k){
			// 	printf("halo\n");
			// }
			// printf("idxSelanjutnya: %d\n",idxSelanjutnya);
			sparse[i][j] = max(sparse[i][j-1], sparse[idxSelanjutnya][j-1]);
			// printf("table[%d][%d]: %d\n",i,j,table[i][j]);
		}
	}
 
}
 
void printSparseTable(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=k;j++){
			if(j){printf(" ");}
			printf("%d",sparse[i][j]);
		}
		printf("\n");
	}
}


int left(int n){return n<<1;}
int right(int n){return (n<<1) + 1;}

void build(int node, int l, int r){
	if(l==r){
		st[node] = a[l];
	
		return;
	}
	int mid = (l+r)/2;
	build(left(node),l,mid);
	build(right(node),mid+1,r);
	st[node] = max(st[left(node)],st[right(node)]);
	
}

int query(int node, int l, int r, int i, int j){
	// printf("node: %d l: %d r: %d i: %d j: %d\n",node, l, r, i, j);
	if(r<i || l>j){
		// printf("returned inf\n");
		return -inf;
	}
	if(i<=l && r<=j){
		// printf("return st[%d]: %d\n", node, st[node]);
		return st[node];
	}//di dlm range 
	int mid = (l+r)/2;
	int ans1 = query(left(node),l,mid,i,j);
	int ans2 = query(right(node),mid+1,r,i,j);
	int ans = max(ans1,ans2);
	
	return ans;

}

void update(int node, int l, int r, int idx, int val){
	if(r<idx || l>idx){return;}//outside range
	if(l==r && l==idx){
		a[idx] = val;
		st[node] = val;
		return;
	}
	int mid = (l+r)/2;
	update(left(node),l,mid,idx,val);
	update(right(node),mid+1,r,idx,val);

	st[node] = max(st[left(node)], st[right(node)]);
}

int querySparse(int l, int r){
	int i,j;
	int idx = l;
	
	// printf("l: %d r: %d\n",l,r);
	int banyak = r-l+1;
	int hasilLog = (int)((double)log2(banyak));
	// printf("l: %d r: %d\n",l,r);
	// printf("banyak: %d hasilLog: %d\n",banyak,hasilLog);
	
	int idxSelanjutnya = r - (1<<hasilLog) + 1;
	int ans = max(sparse[l][hasilLog],sparse[idxSelanjutnya][hasilLog]);
	
	return ans;
}

int findKiri(int building) {
	int kiri = 1, kanan = building, mid, ans;
	while(kiri <= kanan){
		mid = (kiri + kanan)/2;
		int maksHeight = querySparse(mid, building);
		// printf("n: %d mid: %d building: %d\n", n, mid, building);
		// printf("mid: %d building: %d maksHeight: %d\n",mid, building, maksHeight);
		if(maksHeight <= a[building]) {
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	return building - ans;
}

int findKanan(int building) {
	int kiri = building, kanan = n, mid, ans;
	while(kiri <= kanan){
		mid = (kiri + kanan)/2;
		int maksHeight = querySparse(building, mid);
		if(maksHeight <= a[building]) {
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	return ans - building;
}

int findNumSeen(int building) {
	int kiri = findKiri(building);
	int kanan = findKanan(building);
	// printf("kiri: %d kanan: %d returned: %d\n", kiri, kanan, kiri + kanan + 1);
	return kiri + kanan + 1;
}

int main(){
	int q,i,j;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	preprocess();
	// printf("maks 2 3: %d\n",query(1,1,n,2,3));
	while(q--){
		int com;
		scanf("%d",&com);
		if(com == 1) {
			int building;
			scanf("%d",&building);
			printf("%d\n", findNumSeen(building));
		}else if(com == 2){
			int building, height;
			scanf("%d %d",&building, &height);
			update(1,1,n, building, height);
		} else if(com == 3){
			int building1, building2, height;
			scanf("%d %d %d",&building1, &building2, &height);
			for(i=building1;i<=building2;i++){
				update(1,1,n,i,height);
			}
		}
	}
	
	
	return 0;
};