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

const int maxn = 1e5 + 5;
bool isVisited[maxn];
int memo[maxn][2];
bool isLeaf[maxn];

int solve(int node, int flag, int parent){
	int i;
	int ans = 0;
	if(memo[node][flag]!=-1){return memo[node][flag];}
	
	if(flag==0){
		ans = 0;
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			if(v!=parent){ans+=(solve(v,1));}
		}
	}else{
		ans = 1;
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			if(v!=parent){continue;}
			ans+=min(solve(v,1), solve(v,0));
		}
	}
	return memo[node][flag] = ans;
}

int main(){
	int n,i,j;
	int a[maxn],b[maxn];
	
	scanf("%d",&n);
	memset(memo,-1,sizeof memo);
	memset(isLeaf,false,sizeof isLeaf);
	AdjList.assign(n+1,vi());
	for(i=0;i<n-1;i++){
		scanf("%d %d",&a[i],&b[i]);
		AdjList[a[i]].pb(b[i]);
		AdjList[b[i]].pb(a[i]);
	}
	
	int ans1 = solve(1,0);
	int ans2 = solve(1,1);
	// printf("ans1 :%d ans2: %d\n",ans1,ans2);
	int ans = min(ans1,ans2);

	printf("%d\n",ans);
	return 0;
};