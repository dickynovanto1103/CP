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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 10;

int idx[maxn], maks[maxn];
vector<deque<int> > AdjList;

int ans[maxn];
ii tree[4*maxn];

int left(int n){return n*2;}
int right(int n){return (n*2) + 1;}

ii combine(ii a, ii b){
	ii c;
	c.first = max(a.first, a.second + b.first);
	c.second = a.second + b.second;
	return c;
}

void build(int node, int l, int r) {
	if(l == r){
		tree[node] = ii(ans[l], ans[l]);
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		tree[node] = combine(tree[left(node)], tree[right(node)]);
	}
}

ii query(int node, int l, int r, int i, int j) {
	if(r < i || j < l){return ii(-inf,-inf);}
	if(i <= l && r <= j){return tree[node];}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i,j);
	ii ans2 = query(right(node), mid+1, r, i, j);
	if(ans1 == ii(-inf,-inf)){return ans2;}
	if(ans2 == ii(-inf,-inf)){return ans1;}
	return combine(ans1,ans2);

}

void update(int node, int l, int r, int idx, int val) {
	if(idx >= inf){return;}
	if(r < idx || l > idx){return;}
	if(l == idx && r == idx){
		tree[node] = ii(val, val);
	}else{
		int mid = (l+r)/2;
		update(left(node), l, mid, idx, val);
		update(right(node), mid+1, r, idx, val);
		tree[node] = combine(tree[left(node)], tree[right(node)]);
	}
}

void processMaks(int s) {
	for(int i=1;i<=100000;i++){
		maks[i] = inf;
		if(AdjList[i].size() > s){maks[i] = AdjList[i][s];}
	}
}

void processUpdate(int bil, int s, int n) {
	if(AdjList[bil].size() > s) {
		update(1,1,n,maks[bil] + 1, 1);
	}

	if(!AdjList[bil].empty()) {
		AdjList[bil].pop_front();	
	}
	
	if(AdjList[bil].size() > s){
		maks[bil] = AdjList[bil][s];
		update(1,1,n,maks[bil] + 1, -s);
	}
}

void max_self(int &a, int b){
	a = max(a, b);
}

int main(){
	int tc,n,s,i,j;
	scanf("%d",&tc);
	int a[maxn];
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		AdjList.assign(maxn, deque<int>());
		scanf("%d %d",&n,&s);
		memset(idx, 0, sizeof idx);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			AdjList[a[i]].pb(i);
		}
		
		processMaks(s);
		for(i=0;i<n;i++){
			int bil = a[i];
			if(i < maks[bil]){
				ans[i+1] = 1;
			}else if(i == maks[bil]){
				ans[i+1] = -s;
			}else{
				ans[i+1] = 0;
			}
		}

		build(1,1,n);
		int maksimal = 0;
		ii jawab = query(1,1,n,1,n);
		max_self(maksimal, jawab.first);
		for(i=0;i<n;i++){
			//coba turn off i
			int bil = a[i];
			update(1,1,n,i+1,0);
			processUpdate(bil, s, n);
			ii jawab = query(1,1,n,i+1, n);
			max_self(maksimal, jawab.first);
		}
		printf("%d\n",maksimal);
	}
	return 0;
};