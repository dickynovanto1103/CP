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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int maxn = 4e5 + 100;

vector<vi> AdjList;
int a[maxn];
ii st[4*maxn];
int left(int n){return 2*n;}
int right(int n){return 2*n+1;}

void build(int node, int l, int r){
	if(l == r){
		st[node] = ii(a[l], a[l]);
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);

		int arr[4] = {st[left(node)].first, st[left(node)].second, st[right(node)].first, st[right(node)].second};

		int first = inf;
		int second = inf;
		int i;
		for(i=0;i<4;i++){
			first = min(first, arr[i]);
		}
		for(i=0;i<4;i++){
			if(arr[i] == first){continue;}
			else{second = min(second, arr[i]);}
		}

		if(second == inf){
			second = first;	
		}
		
		st[node] = ii(first, second);
	}
}

ii query(int node, int l, int r, int i, int j){
	if(l > r){return ii(inf,inf);}
	if(j < l ||i>r){return ii(inf,inf);}
	if(i<=l && r<=j){return st[node];}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i, j);
	ii ans2 = query(right(node), mid+1, r, i,j);
	int arr[4] = {ans1.first, ans1.second, ans2.first, ans2.second};
	int first = inf;
	int second = inf;
	// printf("l: %d r: %d\n",l,r);
	for(i=0;i<4;i++){
		first = min(first, arr[i]);
	}
	for(i=0;i<4;i++){
		if(arr[i] == first){continue;}
		else{second = min(second, arr[i]);}
	}

	if(second == inf){
		second = first;	
	}
	
	return ii(first,second);
}

void update(int node, int l, int r, int idx, int val) {
	if(idx < l || idx > r){return;}
	if(l == idx && r == idx){
		a[idx] = val;
		st[node] = ii(val,val);
		return;
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx, val);

	int arr[4] = {st[left(node)].first, st[left(node)].second, st[right(node)].first, st[right(node)].second};

	int first = inf;
	int second = inf;
	int i;
	for(i=0;i<4;i++){
		first = min(first, arr[i]);
	}
	for(i=0;i<4;i++){
		if(arr[i] == first){continue;}
		else{second = min(second, arr[i]);}
	}

	if(second == inf){
		second = first;	
	}
	
	st[node] = ii(first, second);
}

int last[maxn];

void removeFromST(int bil, int n){
	int i,j;
	for(i=0;i<AdjList[bil].size();i++){
		int idx = AdjList[bil][i];
		update(1,1,n,idx,inf);
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(maxn, vi());
	memset(last, -1, sizeof last);
	for(i=1;i<=n;i++){

		scanf("%d",&a[i]);
		last[a[i]] = i;
		AdjList[a[i]].pb(i);
	}
	

	build(1,1,n);

	ii ans = ii(inf,inf);
	for(i=1;i<=n;i++){
		int bil = a[i];
		int idxPertama = AdjList[bil][0];
		
		//cari rmq
		ii hasil = query(1,1,n,idxPertama+1,i-1);
		// printf("i: %d bil: %d hasil: %d %d\n",i,bil,hasil.first, hasil.second);
		if(hasil.first != inf){
			if(hasil.first == bil){
				if(hasil.second != bil){
					ans = min(ans, ii(bil, hasil.second));
				}
			}else{
				ans = min(ans, ii(bil, hasil.first));
			}
		}

		// printf("bil: %d\n", );
		if(last[bil] == i){
			// printf("halo bil: %d i: %d\n",bil,i);
			//update semua
			removeFromST(bil,n);
		}
	}
	
	if(ans == ii(inf,inf)){printf("-1\n");}
	else{printf("%d %d\n", ans.first, ans.second);}
	return 0;
};