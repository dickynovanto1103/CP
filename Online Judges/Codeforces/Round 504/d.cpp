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

int st[maxn*4];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l == r){
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);

		st[node] = min(st[left(node)], st[right(node)]);
	}
}

int query(int node, int l, int r, int i, int j){
	if(r < i || l > j){return inf;}
	if(i<=l && r<=j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i, j);
	return min(ans1,ans2);
}

vector<vi> AdjList;

int main(){
	int n,q,i,j;
	bool isVisited[maxn + 10];
	memset(isVisited, false, sizeof isVisited);
	scanf("%d %d",&n,&q);
	a[0] = -1; a[n+1] = -1;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		isVisited[a[i]] = true;
	}

	vi listBil;
	for(i=q;i>=1;i--){
		if(!isVisited[i]){
			listBil.pb(i);
		}
	}

	int ukuran = listBil.size();
	int sisa = n - ukuran;
	for(i=0;i<sisa;i++){
		listBil.pb(1);
	}
	
	bool semua0 = true;
	int idx = 0;

	for(i=1;i<=n;i++){
		if(a[i] == 0){continue;}
		int assign = 0;
		semua0 = false;
		if(a[i-1] == 0){
			assign = listBil[idx];
			if(assign <= a[i]){
				assign = a[i];
			}else{
				idx++;	
			}
			
			for(j=i-1;j>=1;j--){
				if(a[j] == 0){
					a[j] = assign;
				}else{
					break;
				}
			}
		}
		if(a[i+1] == 0){
			assign = listBil[idx];
			if(assign <= a[i]){
				assign = a[i];
			}else{
				idx++;	
			}
			for(j=i+1;j<=n;j++){
				if(a[j] == 0){
					a[j] = assign;
				}else{
					break;
				}
			}
		}
	}

	if(!isVisited[0]){
		if(!isVisited[q]){
			printf("NO\n");
			return 0;
		}
	}

	if(semua0){
		for(i=1;i<=n;i++){
			a[i] = q;
		}
	}

	AdjList.assign(maxn + 10,vi());

	for(i=1;i<=n;i++){
		AdjList[a[i]].pb(i);
	}

	build(1,1,n);

	for(i=1;i<=q;i++){
		int ukuran = AdjList[i].size();
		if(ukuran <= 1){continue;}
		int idx1 = AdjList[i][0];
		int idx2 = AdjList[i][ukuran-1];
		if(idx1 == (idx2-1)){continue;}
		int minim = query(1,1,n,idx1 + 1, idx2 - 1);
		if(minim < i){printf("NO\n"); return 0;}
	}
	
	printf("YES\n");
	for(i=1;i<=n;i++){
		if(i>1){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");

	return 0;
};