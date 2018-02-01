#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
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
ll sum[4*maxn], lazy[4*maxn];
ll a[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n+1;}

void build(int node, int l, int r){
	if(l==r){
		sum[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);

		sum[node] = sum[left(node)] + sum[right(node)];
	}
}

ll query(int node, int l, int r, int i, int j){
	if(lazy[node]!=0){
		// printf("l: %d r: %d i: %d j: %d\n",l,r,i,j);
		sum[node]+=(r-l+1)*lazy[node];
		// printf("sum[%d] jd: %lld setelah dikali oleh lazy: %lld sebanyak: %d kali\n",node,sum[node],lazy[node],(r-l+1));
		if(l!=r){
			lazy[left(node)] += lazy[node];
			lazy[right(node)] += lazy[node];
		}

		lazy[node] = 0;	
	}

	if(i>r || j<l){return -inf;}
	
	if(i<=l && r<=j){
		return sum[node];
	}

	int mid = (l+r)/2;
	ll ans1 = query(left(node),l,mid,i,j);
	ll ans2 = query(right(node),mid+1,r,i,j);
	if(ans1==-inf){return ans2;}
	if(ans2==-inf){return ans1;}
	return ans1+ans2;

}

void update(int node, int l, int r, int i, int j, ll v){
	if(lazy[node]!=0){
		// printf("l: %d r: %d i: %d j: %d\n",l,r,i,j);
		sum[node]+=(r-l+1)*lazy[node];
		// printf("sum[%d] jd: %lld setelah dikali oleh lazy: %lld sebanyak: %d kali\n",node,sum[node],lazy[node],(r-l+1));
		if(l!=r){
			lazy[left(node)] += lazy[node];
			lazy[right(node)] += lazy[node];
		}

		lazy[node] = 0;	
	}
	
	if(i>r || j<l){return;}

	if(i<=l && r<=j){
		sum[node] += (r-l+1)*v;
		// printf("l: %d r: %d i: %d j: %d\n",l,r,i,j);
		// printf("sum[%d] jd: %lld setelah dikali oleh v: %lld sebanyak: %d kali\n",node,sum[node],v,(r-l+1));
		if(l!=r){
			int mid = (l+r)/2;
			lazy[left(node)] += v;
			lazy[right(node)] += v;
		}
		return;
	}

	int mid = (l+r)/2;
	//printf("l: %d r: %d i: %d j: %d mid: %d\n",l,r,i,j,mid);
	update(left(node), l, mid, i, j, v);
	update(right(node), mid+1,r,i,j,v);
	// printf("l: %d r: %d i: %d j: %d mid: %d\n",l,r,i,j,mid);
	sum[node] = sum[left(node)] + sum[right(node)];
	// printf("sum[%d]: %lld\n",node,sum[node]);
}

int main(){
	int tc,n,q,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&q);
		build(1,1,n);
		while(q--){
			int com, l,r;
			ll v;
			scanf("%d %d %d",&com,&l,&r);
			if(com==0){
				scanf("%lld",&v);
				// printf("v: %lld\n",v);
				update(1,1,n,l,r,v);
				//printf("something\n");
			}else{
				printf("%lld\n", query(1,1,n,l,r));
			}
		}
		memset(lazy,0,sizeof lazy);
		memset(sum,0,sizeof sum);
		memset(a,0,sizeof a);
	}
	return 0;
};