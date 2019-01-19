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

vector<vi> AdjList;

const int maxn = 2e5 + 5;

bool isVisited[maxn];

vi ans;

void dfs(int n) {
	isVisited[n] = true;
	printf("%d ",n);
	for(int i=0;i<AdjList[n].size();i++){
		int v = AdjList[n][i];
		if(!isVisited[v]){
			dfs(v);
		}
	}
}

int a[maxn], b[maxn];

bool isValid(int idx1, int idx2, int idx3) {
	if(a[idx2] == idx3 || b[idx2] == idx3) {
		return true;
	}else{
		return false;
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(maxn, vi());
	
	for(i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);

	}
	for(i=1;i<=n;i++){
		int first = a[i], second = b[i];
		if(isValid(i, first, second)){
			AdjList[i].pb(first); AdjList[first].pb(second);
		}else{
			AdjList[i].pb(second); AdjList[second].pb(first);
		}
	}
	memset(isVisited, false, sizeof isVisited);
	dfs(1);
	printf("\n");
	return 0;
};