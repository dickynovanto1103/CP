#include <bits/stdc++.h>
//#include <unordered_map>

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

const int maxn = 500011; 
int a[maxn];
int bit[maxn];
int n;

struct pas { 
	int l, r, idx; 
}; 

bool cmp(pas x, pas y) { 
	return x.r < y.r; 
} 


void update(int idx, int val) { 
	for (; idx <= n; idx += idx&-idx) {
		bit[idx] += val;
	}
} 

int query(int idx) { 
	int sum = 0; 
	for (; idx>0; idx-=idx&-idx) {
		sum += bit[idx]; 
	}
	return sum; 
} 

void solve(pas queries[], int q) 
{
	
	int last_visit[maxn]; 
	memset(last_visit, -1, sizeof(last_visit)); 

	int ans[q]; 
	int cnt = 0; 
	for (int i=0; i<n; i++) { 
		if (last_visit[a[i]] != -1) {
			update (last_visit[a[i]] + 1, -1); 
		}

		last_visit[a[i]] = i; 
		update(i + 1, 1);

		while (cnt < q && queries[cnt].r == i) { 
			ans[queries[cnt].idx] = query(queries[cnt].r + 1) - query(queries[cnt].l); 
			cnt++; 
		} 
	} 

	for (int i=0; i<q; i++) 
		cout << ans[i] << endl; 
} 

pas que[maxn];

int main() { 
	int q;
	scanf("%d %d",&n,&q);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<q;i++){
		scanf("%d %d",&que[i].l, &que[i].r);
		que[i].l--; que[i].r--;
		que[i].idx = i;
	}
	
	sort(que, que+q, cmp); 
	solve(que, q); 
	return 0; 
} 
