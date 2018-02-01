#include <bits/stdc++.h>

using namespace std;
#define inf 1000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int v[101], w[101];

int memo[101][10201], berat[101][10201];
int m,n;

int solve(int id, int total){
	if(total>m && m<1800){return -inf;}
	if(total>m+200){return -inf;}
	if(id==n){
		if(total>m && total<=2000){return -inf;}
		return 0;
	}
	if(memo[id][total]!=-1){return memo[id][total];}
	return memo[id][total]=max(solve(id+1,total), v[id] + solve(id+1,total+w[id]));
}

int main() {
	int i,j;
	while(scanf("%d %d",&m,&n)!=EOF){
		for(i=0;i<n;i++){scanf("%d %d",&w[i],&v[i]);}
		memset(memo,-1,sizeof memo);
		int ans;
		ans = solve(0, 0);
		
		printf("%d\n",ans);
	}
	return 0;
}