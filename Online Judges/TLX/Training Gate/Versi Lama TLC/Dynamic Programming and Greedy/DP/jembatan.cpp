#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 101;
int n;
int memo[maxn][maxn];
int idx[maxn];
int a[maxn],b[maxn];

int solve(int id, int idxMax){
	if(idxMax==n-1 || id==n){return 0;}
	if(memo[id][idxMax]!=-1){return memo[id][idxMax];}
	if(idx[a[id]]<idxMax){return solve(id+1,idxMax);}
	return memo[id][idxMax] = max(1+solve(id+1,max(idx[a[id]],idxMax)), solve(id+1,idxMax));
}

int main() {
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		idx[b[i]] = i;
	}
	memset(memo,-1,sizeof memo);
	int ans = solve(0,0);
	printf("%d\n",ans);
	return 0;
}