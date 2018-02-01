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

const int maxn = 5e4 + 4;
struct Node{
	ll best, sum, prefixSum, suffixSum;
};

Node pas[4*maxn];
ll a[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n+1;}

Node combine(Node a, Node b){
	Node temp;
	// printf("prefixSum a: %lld b: %lld sum a: %lld b: %lld\n",a.prefixSum, b.prefixSum,a.sum, b.sum);
	temp.prefixSum = max(a.prefixSum,max(a.sum,a.sum+b.prefixSum));
	// printf("prefixSum temp: %lld\n",temp.prefixSum);
	temp.sum = a.sum + b.sum;
	temp.suffixSum = max(b.suffixSum,max(b.sum,b.sum+a.suffixSum));
	ll maxSendiri = max(a.sum, max(b.sum, max(a.prefixSum, max(b.prefixSum, max(a.suffixSum, b.suffixSum)))));
	ll maxBest = max(a.best, b.best);
	temp.best = max((max(temp.prefixSum, temp.suffixSum), max(temp.sum,a.suffixSum+b.prefixSum)), max(maxSendiri,maxBest));
	// printf("tempBest: %lld\n",temp.best);

	return temp;
}

void build(int node, int l, int r){

	if(l==r){
		pas[node].best = pas[node].sum = pas[node].prefixSum = pas[node].suffixSum = a[l];
		// printf("l: %d r: %d best: %lld sum: %lld\n",l,r,pas[node].best, pas[node].sum);
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);
		// printf("node: %d l: %d r: %d\n",node,l,r);
		// printf("left(node): %d right(node): %d\n",left(node),right(node));
		pas[node] = combine(pas[left(node)], pas[right(node)]);
		// printf("node: %d l: %d r: %d\n",node,l,r);
		// printf("data hasil combine\n");
		// printf("best: %lld sum: %lld prefixSum: %lld suffixSum: %lld\n",pas[node].best,pas[node].sum,pas[node].prefixSum,pas[node].suffixSum);
	}
}

Node query1(int node, int l, int r, int i, int j){
	Node ans;
	if(j<l || i>r){
		ans.best = -inf;
		return ans;
	}
	if(i<=l && r<=j){
		// printf("masuk sini\n");
		return pas[node];
	}
	int mid = (l+r)/2;
	// printf("node: %d l: %d r: %d i: %d j: %d mid: %d\n",node,l,r,i,j,mid);
	Node ans1 = query1(left(node),l,mid,i,j);
	Node ans2 = query1(right(node),mid+1,r,i,j);
	// printf("best ans1: %lld best ans2: %lld\n",ans1.best, ans2.best);
	if(ans1.best==-inf){return ans2;}
	if(ans2.best==-inf){return ans1;}
	ans = combine(ans1,ans2);
	// printf("ans best: %lld\n",ans.best);
	return ans;
}

ll query(int node, int l, int r, int i, int j){
	// printf("masuk query1\n");
	Node ans = query1(node,l,r,i,j);
	return ans.best;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%lld",&a[i]);}
	build(1,1,n);
	// printf("build selesai\n");
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%lld\n",query(1,1,n,l,r));
	}
	return 0;
};