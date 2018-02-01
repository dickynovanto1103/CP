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

const int maxn = 5e5 + 5;
int a[maxn];
int st[4*maxn];
bool isValid;

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}
void build(int node, int l, int r){
	if(l==r){
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);

		st[node] = __gcd(st[left(node)], st[right(node)]);
		// printf("l: %d r: %d mid: %d st[%d]: %d\n",l,r,mid,node,st[node]);
	}
}

int query(int node, int l, int r, int i, int j){
	if(l>r){return 0;}
	if(l>j || r<i){return 0;}
	if(i<=l && r<=j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i,j);
	int ans = __gcd(ans1,ans2);

	return ans;
}

void telusuri(int node, int l, int r, int i, int j, int x){
	if(l>j || r<i){return;}
	//if(i<=l && r<=j){return;}
	if(!isValid){return;}
	if(l==r){
		isValid = true;
		return;
	}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i,j);
	int ans = __gcd(ans1,ans2);
	if(ans%x==0){isValid = true; return;}
	if(ans1%x!=0 && ans2%x!=0){
		// printf("masuk sini\n");
		isValid = false;
	}else if(ans1%x==0 && ans2%x!=0){//telusuri area ans2
		telusuri(right(node),mid+1,r,i,j,x);
	}else if(ans1%x!=0 && ans2%x==0){
		telusuri(left(node),l,mid,i,j,x);
	}
}

void update(int node, int l, int r, int idx, int val){
	if(l>idx || r<idx){return;}
	if(l==r && l==idx){
		st[node] = val;
		a[idx] = val;
		return;
	}
	int mid = (l+r)/2;
	update(left(node),l,mid,idx,val);
	update(right(node),mid+1,r,idx,val);

	st[node] = __gcd(st[left(node)], st[right(node)]);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	build(1,1,n);
	int q;
	scanf("%d",&q);
	while(q--){

		int com, l,r,x, idx;
		scanf("%d",&com);
		if(com==1){
			scanf("%d %d %d",&l,&r,&x);
			isValid = true;
			telusuri(1,1,n,l,r,x);
			if(isValid){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			scanf("%d %d",&idx,&x);
			update(1,1,n,idx,x);
		}
	}
	return 0;
};