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

const int maxn = 3e5 + 5;
int a[maxn], ans[maxn], temp[maxn], cnt[maxn];
int n,b;

int findFirstDuplicated(){
	set<int> s;
	for(int i=0;i<n;i++){
		if(s.find(a[i]) != s.end()) {
			return i;
		}else{
			s.insert(a[i]);
		}
	}
	return -1;
}

ii st[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

ii combine(ii a, ii b){
	ii ans = ii(min(a.first, b.first), max(a.second, b.second));
	return ans;
}

void build(int node, int l, int r) {
	if(l == r){
		st[node] = ii(cnt[l], cnt[r]);
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		st[node] = combine(st[left(node)], st[right(node)]);
	}
}

ii query(int node, int l, int r, int i, int j) {
	if(i > j){return ii(inf,inf);}
	if(r < i || j < l){return ii(inf, inf);}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i, j);
	ii ans2 = query(right(node), mid+1, r, i, j);
	if(ans1 == ii(inf,inf)){return ans2;}
	if(ans2 == ii(inf, inf)){return ans1;}
	ii ans = combine(ans1, ans2);
	return ans;
}

void update(int node, int l, int r, int idx, int val) {
	if(r < idx || l > idx){return;}
	if(idx == l && l == r){
		// printf("idx: %d val: %d\n",idx, val);
		st[node] = ii(val,val);
		return;
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx, val);
	st[node] = combine(st[left(node)], st[right(node)]);
}

int main(){
	int i,j;
	
	scanf("%d %d",&n,&b);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]++;
		cnt[a[i]]++;
		// printf("cnt[%d]: %d\n",a[i], cnt[a[i]]);
	}
	build(1,1,b);
	int idx = -1;
	for(i=n-1;i>=0;i--){
		cnt[a[i]]--;
		update(1,1,b, a[i], cnt[a[i]]);
		ii ansMinim = query(1,1,b,a[i]+1, b);
		ii ansMaks = query(1,1,b,1,b);
		ii ans = ii(ansMinim.first, ansMaks.second);
		// printf("i: %d query: %d %d ans: %d %d\n",i,a[i]+1, b, ans.first, ans.second);
		if(ans == ii(0, 1) || ans==ii(0,0)){
			idx = i;
			break;
		}
	}
	if(idx == -1){
		// printf("halo\n");
		printf("1 0");
		for(i=2;i<=n;i++){
			printf(" %d",i);
		}
		printf("\n");
	}else{
		set<int> s;
		for(i=0;i<n;i++){
			a[i]--;
		}
		for(i=0;i<idx;i++){
			s.insert(a[i]);
			ans[i] = a[i];
		}
		for(i=a[idx]+1;i<b;i++){
			if(s.find(i) == s.end()){
				ans[idx] = i;
				s.insert(i);
				break;
			}
		}
		vi listBil;
		for(i=0;i<b;i++){
			if(s.find(i) == s.end()){
				listBil.pb(i);
			}
		}
		int indeks = 0;
		for(i=idx+1;i<n;i++){
			ans[i] = listBil[indeks++];
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}

	

	return 0;
};