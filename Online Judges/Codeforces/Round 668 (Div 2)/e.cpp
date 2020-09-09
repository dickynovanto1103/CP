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

const int maxn = 3e5 + 5;
int a[maxn];
int bit[maxn];
int ans[maxn];

int query(int idx) {
	int ans = 0;
	for(int i=idx;i>=1;i -= (i&-i)) {
		ans += bit[i];
	}
	return ans;
}

int n;

void update(int idx, int val) {
	if(idx <= 0){return;}
	for(int i=idx;i<=n;i+=(i&-i)){
		bit[i] += val;
	}
}

int findLargestIdx(int target, int maksIdx) {
	int kiri = 1, kanan = maksIdx, mid, ans = -1;
	while(kiri <= kanan){
		mid = (kiri + kanan) / 2;
		if((query(maksIdx) - query(mid-1)) >= target) {
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	return ans;
}

int main(){
	int q,i,j;
	scanf("%d %d",&n,&q);

	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i] = i - a[i];
	}

	vector<vi> listKiri, listIdx;
	listKiri.assign(n+1, vi());
	listIdx.assign(n+1, vi());

	for(i=1;i<=q;i++){
		int x, y;
		scanf("%d %d",&x,&y);
		int start = 1 + x, end = n - y;
		listKiri[end].pb(start);
		listIdx[end].pb(i);
	}

	for(int r=1;r<=n;r++){
		// printf("r: %d\n",r);
		if(a[r] >= 0) {
			int largestIdx = findLargestIdx(a[r], r);
			update(largestIdx, 1);
		}
		for(i=0;i<listKiri[r].size();i++){
			int kiri = listKiri[r][i];
			int idxQuery = listIdx[r][i];
			ans[idxQuery] = query(r) - query(kiri-1);
		}
	}

	for(i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
	
	return 0;
};