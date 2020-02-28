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

const int maxn = 2e5 + 5;

int a[maxn];

ii b[maxn];

int st[2][4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n+1;}

void build(int node, int l, int r, int *st, int *a) {
	if(l == r){
		st[node] = a[l];
		return;
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid, st, a);
		build(right(node), mid+1, r, st, a);
		st[node] = max(st[left(node)], st[right(node)]);
	}
}

int query(int node, int l, int r, int i, int j, int *st) {
	if(r < i || l > j){return 0;}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	return max(query(left(node), l, mid, i, j, st), query(right(node), mid+1, r, i, j, st));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d",&n);
		int maks1 = 0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			maks1 = max(maks1, a[i]);
		}
		build(1,1,n,st[0],a);
		scanf("%d",&m);
		int maks2 = 0;
		for(i=1;i<=m;i++){
			scanf("%d %d",&b[i].first,&b[i].second);
			maks2 = max(maks2, b[i].first);
		}
		if(maks1 > maks2){printf("-1\n");continue;}
		sort(b+1, b+m+1);
		int temp[m+1];
		for(i=1;i<=m;i++){temp[i] = b[i].second;}
		build(1,1,m,st[1],temp);
		// for(i=1;i<=m;i++){
		// 	printf("temp[%d]: %d pertama: %d\n",i,temp[i], b[i].first);
		// }
		int idx = 1, cnt = 0;
		while(idx <= n){
			int sisa = n-idx+1;
			int kiri = 1, kanan = sisa, mid, ans;
			// printf("idx: %d sisa: %d\n",idx,sisa);
			while(kiri <= kanan) {
				mid = (kiri+kanan)/2;
				// printf("mid: %d\n",mid);
				maks1 = query(1,1,n,idx, idx+mid-1, st[0]);
				int idx1 = lower_bound(b+1, b+1+m, ii(maks1, 0)) - (b);
				debug printf("cari; %d %d\n",maks1, 0);
				debug printf("idx :%d elemen: %d %d\n",idx1, b[idx1].first, b[idx1].second);
				maks2 = query(1,1,m,idx1,m,st[1]);
				// printf("maks2: %d dari %d sampe %d\n",maks2, idx1, m);
				if(maks2 >= mid){
					ans = mid;
					kiri = mid+1;
				}else{
					kanan = mid-1;
				}
			}
			idx += ans;
			cnt++;
			// printf("idx jd: %d cnt: %d\n",idx, cnt);
		}
		printf("%d\n",cnt);
	}
	return 0;
};