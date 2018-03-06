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
int st[4*maxn], a[maxn];
int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l==r){
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);

		st[node] = st[left(node)] & st[right(node)];
	}
}

int query(int node, int l, int r, int i, int j){
	if(l>j || r<i){return -1;}
	if(i<=l && r<=j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1,r,i,j);
	if(ans1==-1){return ans2;}
	if(ans2==-1){return ans1;}
	return ans1 & ans2;
}

int main(){
	int tc,i,j,n,q;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		build(1,1,n);
		scanf("%d",&q);
		while(q--){
			int l,r;
			scanf("%d %d",&l,&r);
			// printf("l: %d r: %d\n",l,r);
			int ans = query(1,1,n,l,r);
			printf("%d\n",ans);
		}
	}
	return 0;
};