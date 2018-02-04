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
int st[4*maxn], a[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}
void build(int node, int l, int r){
	if(l==r){
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l,mid);
		build(right(node),mid+1,r);
		st[node] = __gcd(st[left(node)], st[right(node)]);
	}
}

int query(int node, int l, int r, int i, int j){
	if(i>j){return 0;}
	if(i>r || j<l){return 0;}
	if(i<=l && r<=j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node),l,mid,i,j);
	int ans2 = query(right(node),mid+1,r,i,j);
	return __gcd(ans1,ans2);
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		int q;
		scanf("%d %d",&n,&q);
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		build(1,1,n);
		while(q--){
			int l,r;
			scanf("%d %d",&l,&r);
			int ans1 = query(1,1,n,1,l-1);
			int ans2 = query(1,1,n,r+1,n);
			printf("%d\n",__gcd(ans1,ans2));
		}
	}
	return 0;
};