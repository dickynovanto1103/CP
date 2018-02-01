#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,titik[55],memo[55][55];

int solve(int left, int right){
	if(left==right-1){return 0;}//ga perlu cut lagi
	if(memo[left][right]!=-1){return memo[left][right];}
	int ans = inf;
	//printf("titik[%d]: %d titik[%d]: %d\n",left,titik[left],right,titik[right]);
	for(int i=left+1;i<right;i++){
		ans = min(ans,solve(left,i)+solve(i,right)+(titik[right]-titik[left]));
		//printf("ans jd: %d\n",ans);
	}
	return memo[left][right] = ans;
}

int main() {
	int l,i;
	while(scanf("%d",&l),l){
		scanf("%d",&n);
		titik[0] = 0;
		for(i=1;i<=n;i++){scanf("%d",&titik[i]);}
		titik[n+1] = l;
		//for(i=0;i<=n;i++){printf("%d\n",titik[i]);}

		memset(memo,-1,sizeof memo);
		int ans = solve(0, n+1);
		printf("The minimum cutting is %d.\n",ans);
	}
	return 0;
}