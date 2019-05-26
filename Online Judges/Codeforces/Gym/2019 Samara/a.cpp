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

vector<vi> neg, pos;

const int maxn = 5e5 + 5;

int left(int n){return 2*n+1;}
int right(int n){return 2*n+2;}

int st[4*maxn];
int ans[maxn];

void build(int node, int l, int r) {
	if(l == r){
		st[node] = ans[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		st[node] = min(st[left(node)], st[right(node)]);
	}
}

int query(int node, int l, int r, int i, int j){
	if(r < i || l > j){return inf;}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i, j);
	return min(ans1, ans2);
}

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	pos.assign(n+1,vi());
	neg.assign(n+1, vi());
	int a[maxn];
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		a[i] = bil;
		if(bil > 0){
			pos[bil].pb(i);	
		}else{
			neg[-bil].pb(i);
		}
	}
	
	for(i=0;i<n;i++){
		if(a[i] < 0) {
			//cari terdekatnya dimana
			a[i] = -a[i];
			int idx = lower_bound(pos[a[i]].begin(),pos[a[i]].end(), i)-pos[a[i]].begin();
			if(idx == pos[a[i]].size()){
				//ya berarti ga ada bound
				ans[i] = n-1;
			}else{
				int idxGagal = pos[a[i]][idx];
				ans[i] = idxGagal-1;
			}
			a[i] = -a[i];
		}
	}

	for(i=0;i<n;i++){
		if(a[i] > 0){
			int idx = lower_bound(neg[a[i]].begin(),neg[a[i]].end(), i)-neg[a[i]].begin();
			if(idx == neg[a[i]].size()){
				//ya berarti ga ada bound
				ans[i] = n - 1;
			}else{
				int idxGagal = neg[a[i]][idx];
				ans[i] = ans[idxGagal];
			}
		}
	}

	build(0,0,n-1);
	for(i=0;i<n;i++){
		int minim = query(0,0,n-1,i,ans[i]);
		int jarak = minim - i + 1;
		if(i){printf(" ");}
		printf("%d",jarak);
	}
	printf("\n");



	return 0;
};