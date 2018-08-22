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

const int maxn = 710;

vector<vi> AdjList;

bool isVisited[maxn];

void dfs(int node){
	isVisited[node] = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(!isVisited[v]){
			dfs(v);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	map<int,int> mapper;
	int a[maxn];
	AdjList.assign(maxn,vi());
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		mapper[a[i]] = i;
	}
	for(i=0;i<n;i++){
		int bil = a[i];
		int idx1 = mapper[bil];
		for(j=0;j<n;j++){
			if(j==i){continue;}
			int bil2 = a[j];
			if(__gcd(bil,bil2)!=1){
				int idx2 = mapper[bil2];
				AdjList[idx1].pb(idx2);
			}
		}
	}
	int cnt = 0;
	for(i=0;i<n;i++){
		if(!isVisited[i]){
			dfs(i);
			cnt++;
		}
	}
	if(cnt > 1){printf("No\n");}
	else{printf("Yes\n");}
	return 0;
};