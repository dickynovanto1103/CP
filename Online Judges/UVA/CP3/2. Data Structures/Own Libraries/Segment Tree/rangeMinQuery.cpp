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

const int maxn = 1e5 + 5;
int st[4*maxn];
int a[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l==r){
		st[node] = a[l];
	
		return;
	}
	int mid = (l+r)/2;
	build(left(node),l,mid);
	build(right(node),mid+1,r);
	st[node] = min(st[left(node)],st[right(node)]);
	
}

int query(int node, int l, int r, int i, int j){
	
	if(r<i || l>j){return inf;}
	if(i<=l && r<=j){
	
		return st[node];
	}//di dlm range 
	int mid = (l+r)/2;
	int ans1 = query(left(node),l,mid,i,j);
	int ans2 = query(right(node),mid+1,r,i,j);
	int ans = min(ans1,ans2);
	
	return ans;

}

void update(int node, int l, int r, int idx, int val){
	if(r<idx || l>idx){return;}//outside range
	if(l==r && l==idx){
		a[idx] = val;
		st[node] = val;
		return;
	}
	int mid = (l+r)/2;
	update(left(node),l,mid,idx,val);
	update(right(node),mid+1,r,idx,val);

	st[node] = min(st[left(node)], st[right(node)]);
}

int main(){
	int n,q,i,j;
	
	while(scanf("%d %d",&n,&q)!=EOF){
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		build(1,1,n);
		//printf("builded\n");
		for(i=0;i<q;i++){
			char com;
			int l,r;
			scanf("\n%c %d %d",&com, &l,&r);
			if(com=='q'){
				printf("%d\n",query(1,1,n,l,r));
			}else{
				update(1,1,n,l,r);
			}
		}
	}
	return 0;
};