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
int a[maxn];
int lazy[4*maxn], st[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n+1;}
void build(int node, int l, int r){
	if(l==r){
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);
	}
}

void update(int node, int l, int r, int i, int j, int valAwal, int valAkhir){
	if(lazy[node]!=0){
		if(l!=r){
			lazy[left(node)] = lazy[node];
			lazy[right(node)] = lazy[node];
		}else{
			a[l] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(j<l || i>r){return;}
	if(i<=l && r<=j){
		if(l!=r){
			lazy[left(node)] = lazy[node];
			lazy[right(node)] = lazy[node];
		}else{
			a[l] = lazy[node];
		}
		return;
	}

	int mid = (l+r)/2;
	update(left(node),l,mid,i,j,valAwal,valAkhir)
}

int main(){
	int n,i,j;
	
	int q;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	build(1,1,n);
	scanf("%d",&q);
	while(q--){
		int l,r,x,y;
		scanf("%d %d %d %d",&l,&r,&x,&y);
		update(1,1,n,l,r,x,y);
	}
	clearLazy(1,1,n);
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
};