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

const int maxn = 640000;
int bit[maxn+10][101];

vector<vi> AdjList;
int euler[maxn];
int cnt = 1;

void dfs(int node){
	euler[cnt++] = node;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		dfs(v);
		euler[cnt++] = node;
	}
}

void update(int idx, int col, int penambahan){
	for(int i=idx;i<=maxn;i+=(i&-i)){
		bit[i][col] += penambahan;
	}
}

int query(int idx, int col){
	int sum = 0;
	if(idx == 0){return 0;}
	for(int i=idx;i>=1;i-=(i&-i)){
		sum += bit[i][col];
	}
	return sum;
}
int warna[300010];

int first[maxn], last[maxn];

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	AdjList.assign(n+1,vi());
	memset(first, -1, sizeof first);
	for(i=1;i<=n;i++){
		int color;
		scanf("%d",&color);
		warna[i] = color;
	}
	for(i=2;i<=n;i++){
		int parent;
		scanf("%d",&parent);
		AdjList[parent].pb(i);
	}

	dfs(1);

	for(i=1;i<=cnt;i++){
		int node = euler[i];
		if(first[node] == -1){
			first[node] = i;
		}
		last[node] = i;
	}

	for(i=1;i<=n;i++){
		update(first[i], warna[i], 1);
	}

	while(q--){
		int k,x;
		scanf("%d %d",&k,&x);
		if(k==0){//query
			int ans = 0;
			for(i=1;i<=100;i++){
				int jumlah = query(last[x], i) - query(first[x]-1, i);
				if(jumlah & 1){
					ans++;
				}
			}
			printf("%d\n",ans);
		}else{
			int warnaAwal = warna[x];
			update(first[x], warnaAwal, -1);
			int warnaBaru = k;
			warna[x] = warnaBaru;
			update(first[x], warnaBaru, 1);
		}
	}
	return 0;
};