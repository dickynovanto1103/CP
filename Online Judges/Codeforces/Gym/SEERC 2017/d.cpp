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

vector<vi> AdjList;

bool isVisited[maxn];

int dfs(int node){
	int ans = 1;
	isVisited[node] = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]){
			ans+=dfs(v);
		}
	}
	return ans;
}

int main(){
	int n,m,i,j;
	int awal[maxn];
	memset(awal, 0, sizeof awal);
	scanf("%d %d",&n,&m);
	memset(isVisited, false, sizeof isVisited);
	AdjList.assign(n+1,vi());
	for(i=1;i<=n;i++){
		int banyak;
		scanf("%d",&banyak);
		for(j=0;j<banyak;j++){
			int idx;
			scanf("%d",&idx);
			if(awal[idx] == 0){
				awal[idx] = i;
			}else{
				AdjList[i].pb(awal[idx]);
				AdjList[awal[idx]].pb(i);
			}
		}
	}

	int ans = 0;
	for(i=1;i<=n;i++){
		if(!isVisited[i]){
			int banyakTambahan = dfs(i) - 1;

			ans+=banyakTambahan;
			// printf("i: %d banyakTambahan: %d ans jd: %d\n",i,banyakTambahan,ans);
		}
	}
	printf("%d\n",ans);
	return 0;
};