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

const int maxn = 80000+1;

int lazy[maxn*4];
int st[4*maxn];
bool val[maxn];
int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void pushDown(int node, int val) {
	lazy[left(node)] = val;
	lazy[right(node)] = val;
}

void handleLazy(int node, int l, int r) {
	if(lazy[node]) {
		st[node] = lazy[node];
		lazy[node] = 0;
		if(l != r) {
			pushDown(node, st[node]);
		}
	}
}

void update(int node, int l, int r, int i, int j, int val) {
	if(r < i || l > j){return;}
	handleLazy(node, l, r);
	if(i <= l && r <= j){
		st[node] = val;
		if(l != r){
			pushDown(node, val);	
		}
		
		return;
	}
	
	int mid = (l+r)/2;
	update(left(node), l, mid, i, j, val);
	update(right(node), mid+1, r, i, j, val);
}

int query(int node, int l, int r, int idx) {
	if(r < idx || l > idx){
		return 0;
	}
	handleLazy(node, l, r);
	if(idx == l && l == r) {
		return st[node];
	}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, idx);
	int ans2 = query(right(node), mid+1, r, idx);
	return max(ans1,ans2);
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--) {
		memset(lazy, 0, sizeof lazy); memset(st, 0, sizeof st);
		memset(val, false, sizeof val);
		int n;
		scanf("%d",&n);
		int maksVal = 0;
		map<int, int> mapper;
		set<int> s;
		int l[maxn], r[maxn];
		for(int i=1;i<=n;i++){
			scanf("%d %d",&l[i],&r[i]);
			s.insert(l[i]); s.insert(r[i]);
			// maksVal = max(maksVal, r);
			// update(1,1,maxn-1,l,r,i);
		}
		int cnt = 1;
		for(set<int>::iterator it = s.begin();it!=s.end();it++) {
			mapper[*it] = cnt++;
		}

		for(i=1;i<=n;i++) {
			int kiri = mapper[l[i]], kanan = mapper[r[i]];
			// printf("i: %d kiri: %d kanan: %d\n",i,kiri, kanan );
			update(1,1,maxn-1,kiri,kanan,i);
		}

		for(i=1;i<=maxn-1;i++){
			int ans = query(1,1,maxn-1,i);
			// if(i > 11){break;}
			// printf("i: %d ans: %d\n",i,ans );
			val[ans] = true;
		}
		int ans = 0;
		for(i=1;i<maxn;i++){
			if(val[i]){ans++;}
		}
		printf("%d\n", ans);
		// s.clear();
	}
	return 0;
};