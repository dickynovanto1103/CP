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

int findLargestIdx(int target, int maksIdx) { //the idea here is that we want to know the least length needed to the left to make the particular target can be removed..O(log^2(n))
	int now = query(maksIdx);
	int tempNow = now;
	//find the most right idx such that idx <= maksIdx and f(idx, maksIdx) >= target
	int pos = 0;
	int logn = int(log2(maksIdx));
	// printf("logn: %d now: %d maksIdx: %d\n",logn, now, maksIdx);

	for(int i=logn;i>=0;i--){
		int nextIdx = pos + (1<<i);
		// printf("pos: %d i: %d nextIdx: %d now: %d bit[%d]: %d\n",pos, i, nextIdx, now, nextIdx, bit[nextIdx]);
		if(nextIdx <= maksIdx && now - bit[nextIdx] >= target) {
			pos += (1<<i);
			now -= bit[nextIdx];
		}
	}
	if(now == tempNow && now >= target) {
		return max(pos, 1);
	}
	// printf("target: %d maksIdx: %d pos: %d\n", target, maksIdx, pos);
	if (tempNow == now) { //ga bs berkurang
		return -1;
	}
	return min(pos + 1, maksIdx);
}

int main(){
	int q,i,j;
	scanf("%d %d",&n,&q);

	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i] = i - a[i];
		// printf("a[%d]: %d\n",i, a[i]);
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