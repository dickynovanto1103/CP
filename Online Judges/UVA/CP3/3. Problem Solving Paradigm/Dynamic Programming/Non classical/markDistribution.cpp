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

int n,memo[71][71];

int solve(int id, int sisa){
	if(id==n){
		if(sisa==0){return 1;}
		else{return 0;}
	}
	if(sisa<0){return 0;}
	if(memo[id][sisa]!=-1){return memo[id][sisa];}
	int ans=0;
	for(int i=0;i<=sisa;i++){
		ans+=solve(id+1,sisa-i);
	}
	return memo[id][sisa] = ans;
}

int main() {
	int tc,t,p;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&t,&p);
		memset(memo,-1,sizeof memo);
		int ans = solve(0,t-n*p);
		printf("%d\n",ans);
	}
	return 0;
}