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
int lazy[4*maxn], st[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}
void build(int node, int l, int r){
	if(l==r){
		st[node] = 0;
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);

		st[node] = st[left(node)] + st[right(node)];
	}
}

int query(int node, int l, int r, int i, int j){
	if(lazy[node]!=0){
		if(lazy[node]%2==1){
			st[node] = (r-l+1)-st[node];
			if(l!=r){
				lazy[left(node)]+=lazy[node];
				lazy[right(node)]+=lazy[node];
			}
		}
		lazy[node] = 0;
	}

	if(i>r || j<l){return 0;}
	if(i<=l && r<=j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node),l,mid,i,j);
	int ans2 = query(right(node),mid+1,r,i,j);
	return ans1+ans2;

}

void update(int node, int l, int r, int i, int j){
	if(lazy[node]!=0){
		if(lazy[node]%2==1){
			st[node] = (r-l+1)-st[node];
			if(l!=r){
				lazy[left(node)]+=lazy[node];
				lazy[right(node)]+=lazy[node];		
			}
			
		}
		lazy[node] = 0;
	}

	if(i>r || j<l){return;}
	if(i<=l && r<=j){
		st[node] = (r-l+1) - st[node];
		if(l!=r){
			lazy[left(node)]++;
			lazy[right(node)]++;
		}
		return;
	}

	int mid = (l+r)/2;
	update(left(node),l,mid,i,j);
	update(right(node),mid+1,r,i,j);

	st[node] = st[left(node)] + st[right(node)];
}

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	build(1,1,n);
	while(q--){
		int com, l, r;
		scanf("%d %d %d",&com,&l,&r);
		if(com==0){
			update(1,1,n,l,r);
		}else{
			printf("%d\n",query(1,1,n,l,r));
		}
	}
	return 0;
};