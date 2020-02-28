#include <bits/stdc++.h>
 
using namespace std;
#define inf 2000000000
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
 
const int maxn = 2e5 + 5;
 
int ar[maxn];
int n;
 
ii st[9][4*maxn];
 
int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}
 
ii combine(ii a, ii b) {
	if(a > b){
		swap(a,b);
	}
	return ii(a.first, min(a.second, min(b.first, b.second)));
	vi v;
	if(a.first == inf){
		if(b.first == inf){
			return ii(inf,inf);
		}else{
			return b;
		}
	}else{
		v.pb(a.first); v.pb(a.second); v.pb(b.first); v.pb(b.second);
		sort(v.begin(), v.end());
		return ii(v[0], v[1]);	
	}
	
}
 
ii query(int node, int l, int r, int i, int j, int idx) {
	if(r < i || l > j){return ii(inf,inf);}
	if(i <= l && r <= j){return st[idx][node];}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i, j, idx);
	ii ans2 = query(right(node), mid+1, r, i,j,idx);
	return combine(ans1, ans2);
}
 
void update(int node, int l, int r, int idx, int val, int indeks) {
	if(idx < l || idx > r){return;}
	if(l == idx && r == idx){
		st[indeks][node] = ii(val, inf);
	}else{
		int mid = (l+r)/2;
		update(left(node), l, mid, idx, val, indeks);
		update(right(node), mid+1, r, idx, val, indeks);
		st[indeks][node] = combine(st[indeks][left(node)], st[indeks][right(node)]);
	}
}

void parse(int bil, int idx) {
	int temp = bil;
	for(int i=0;i<9;i++){
		int angka = bil%10;
		bil/=10;

		if(angka != 0){
			update(1,1,n,idx,temp, i);
		}else{
			update(1,1,n,idx,inf,i);
		}
	}
}
 
int main(){
	int m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&ar[i]);
		parse(ar[i], i);
	}
 
	for(i=0;i<m;i++){
		int com;
		scanf("%d",&com);
		if(com == 1) {
			int idx, val;
			scanf("%d %d",&idx, &val);
			parse(val, idx);
		}else{
			int l, r;
			scanf("%d %d",&l,&r);
			if(l == r){printf("-1\n"); continue;}
			int minim = inf;
			for(j=0;j<9;j++){
				ii ans = query(1,1,n,l,r,j);
				if(ans.first != inf && ans.second != inf){
					minim = min(minim, ans.first + ans.second);
				}
			}
			if(minim == inf){
				printf("-1\n");
			}else{
				printf("%d\n",minim);
			}
			
		}
	}
	return 0;
};