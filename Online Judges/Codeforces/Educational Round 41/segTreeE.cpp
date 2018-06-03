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

const int maxn = 2e5 + 5;

vector<vi> AdjList;
ll st[4*maxn];
ll temp[maxn];
int n;

int left(int n) {
	return 2*n;
}

int right(int n) {
	return 2*n + 1;
}

void build(int node, int l, int r) {
	if(l == r){
		st[node] = temp[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);

		st[node] = st[left(node)] + st[right(node)];
	}
}

int query(int node, int l, int r, int i, int j) {
	if(r < i || l > j) { //di luar rentang yang diinginkan
		return 0;
	}

	if(l>=i && r<=j) { //di dalam rentang yang diinginkan
		return st[node];
	}

	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i,j);
	return ans1 + ans2;
}

void update(int node, int l, int r, int idx, int value) {
	if(idx < l || idx > r) { //di luar range
		return;
	}
	if(l == idx && r == idx){
		st[node] = value;
		temp[idx] = value;
		return;
	}

	int mid = (l+r)/2;
	update(left(node), l, mid, idx, value);
	update(right(node), mid+1, r, idx, value);

	st[node] = st[left(node)] + st[right(node)];
}


int main(){
	int i,j,a[maxn];
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	priority_queue<ii,vii, greater<ii> > pq;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i] = min(a[i], n);
		AdjList[a[i]].pb(i);
		temp[i] = 1;
		pq.push(ii(a[i],i));
	}
	build(1,1,n);
	ll ans = 0;

	for(i=1;i<=n;i++){
		while(!pq.empty() && pq.top().first < i) {
			ii front = pq.top(); pq.pop();
			update(1, 1, n, front.second, 0);
		}
		if(a[i] > i) {
			ll jawab = query(1,1,n,i+1,a[i]);

			ans+=jawab;
		}
		
	}
	printf("%lld\n",ans);
	return 0;
};