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

const int maxn = (1<<17);
int st[4*maxn + 10],a[maxn + 10];
bool isGenap;

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void combine(int node, int depth){
	if(!isGenap){
		if(depth % 2 ==0){//or
			st[node] = st[left(node)] | st[right(node)];
		}else{
			st[node] = st[left(node)] ^ st[right(node)];
		}
	}else{
		// printf("depth: %d\n",depth);
		if(depth % 2 ==0){//xor
			st[node] = st[left(node)] ^ st[right(node)];
			// printf("st[%d] = st[%d] ^ st[%d] ==> %d = %d ^ %d\n",node,left(node), right(node), st[node], st[left(node)], st[right(node)]);
		}else{
			st[node] = st[left(node)] | st[right(node)];
			// printf("st[%d] = st[%d] | st[%d] ==> %d = %d | %d\n",node,left(node), right(node), st[node], st[left(node)], st[right(node)]);
		}
	}
}

void build(int node, int l, int r, int depth) {
	if(l==r) {
		// printf("depth: %d\n",depth);
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid, depth+1);
		build(right(node), mid+1, r, depth+1);
		combine(node, depth);
	}
}

void update(int node, int l, int r, int idx, int val, int depth) {
	if(idx > r || idx < l){
		return;
	}
	if(idx == l && idx == r) {
		st[node] = val;
		// printf("masuk idx: %d val: %d ada assignment st[%d]: %d\n",idx,val,node,val);
		// a[idx] = val;
		return;
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val, depth+1);
	update(right(node), mid+1, r, idx, val, depth+1);
	combine(node, depth);
}

int query(){
	return st[1];
}

int main(){
	int n,q,i;
	scanf("%d %d",&n,&q);
	for(i=1;i<=(1<<n);i++){
		scanf("%d",&a[i]);
	}
	if(n%2==0){isGenap = true;}
	else{isGenap = false;}
	build(1,1,(1<<n),0);
	// printf("query: %d\n", query());
	while(q--){
		int idx, val;
		scanf("%d %d",&idx,&val);
		// int nilaiAwal = a[idx];
		// a[idx] = val;
		update(1,1,(1<<n),idx,val, 0);
		printf("%d\n",query());
		// update(1,1,(1<<n),idx,nilaiAwal,0);
		// printf("setelah query %d\n",query());
	}
	return 0;
};