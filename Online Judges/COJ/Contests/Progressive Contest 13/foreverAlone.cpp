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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int BLOCK_SIZE;

struct query {
	int l,r,idx;
};

bool cmp(query a, query b){
	if(a.l/BLOCK_SIZE != b.l/BLOCK_SIZE){return a.l/BLOCK_SIZE < b.l/BLOCK_SIZE;}
	return a.r < b.r;
}

int jawab = 0;

bool cnt[61];

int a[maxn];

void add(int idx) {
	// printf("tambah idx: %d\n",idx);
	cnt[a[idx]] = !cnt[a[idx]];
	if(cnt[a[idx]]) {
		jawab++;
	}else{
		jawab--;
	}
	// printf("jawab jd: %d\n",jawab);
}

void remove(int idx) {
	cnt[a[idx]] = !cnt[a[idx]];
	if(cnt[a[idx]]) {
		jawab++;
	}else{
		jawab--;
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	int ans[maxn];
	query que[maxn];

	while(tc--){
		int n;
		scanf("%d",&n);
		memset(cnt, false, sizeof cnt);
		BLOCK_SIZE = sqrt(n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}

		int q;
		scanf("%d",&q);
		
		for(int tt=0;tt<q;tt++){
			scanf("%d %d",&que[tt].l,&que[tt].r);
			que[tt].idx=tt;
		}
		sort(que, que + q,cmp);
		jawab = 1;
		// for(i=0;i<q;i++){
		// 	printf("%d %d %d\n",que[i].l,que[i].r,que[i].idx);
		// }
		int start = que[0].l, end = start;
		cnt[a[start]] = true;
		for(i=0;i<q;i++){
			int kiri = que[i].l, kanan = que[i].r;
			// printf("kiri: %d kanan: %d\n",kiri, kanan);
			// printf("i: %d\n",i);
			while(start > kiri) {
				// printf("start berkurang jd: %d\n", start-1);
				add(--start);
			}
			while(end < kanan) {
				// printf("end tambah jd: %d\n", end+1);
				add(++end);
			}
			while(start < kiri) {
				// printf("start tambah jd: %d\n", start+1);
				remove(start++);
			}
			while(end > kanan) {
				// printf("end berkurang jd: %d\n", end-1);
				remove(end--);
			}
			int idx = que[i].idx;
			ans[idx] = jawab;
		}
		for(i=0;i<q;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
};