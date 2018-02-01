#include <bits/stdc++.h>

using namespace std;
#define inf 1000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,p,w[1001],v[1001];
int memo[1001][1001][2];

int solve(int id, int money, int sedangNaikPesawat){
	if(money<0){return -inf;}
	if(id>=n-1){return 0;}
	if(memo[id][money][sedangNaikPesawat]!=-1){return memo[id][money][sedangNaikPesawat];}
	int a = v[id]+solve(id+1,money-w[id],0);
	int b = solve(id+1,money-p,1);
	int c = -inf;
	if(sedangNaikPesawat==1){c = max(c,solve(id+1,money,1));}
	int maks = max(a,max(b,c));
	return memo[id][money][sedangNaikPesawat] = maks;
}


int main() {
	int tc,money,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&money,&p);
		for(i=0;i<n-1;i++){scanf("%d %d",&w[i],&v[i]);}
		//printf("money: %d\n",money);
		memset(memo,-1,sizeof memo);
		int ans = solve(0,money,0);
		if(ans<0){printf("-1\n");}
		else{printf("%d\n",ans);}
	}

	return 0;
}