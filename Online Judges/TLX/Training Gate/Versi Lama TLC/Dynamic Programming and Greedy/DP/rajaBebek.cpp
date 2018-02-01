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

const int maxn = 1000;
ll memo[maxn][1001];
int a[maxn], n;

ll solve(int id, int total){
	if(total==0){return 0;}
	if(id==maxn){return inf;}
	if(total<a[id]){return solve(id+1,total);}
	if(memo[id][total]!=-1){return memo[id][total];}
	return memo[id][total] = min(1+solve(id+1,total-a[id]), solve(id+1,total));
}

int main() {
	int total,i;
	scanf("%d %d",&n,&total);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	//printf("test\n");
	memset(memo,-1,sizeof memo);
	ll ans = solve(0,total);
	if(ans>=inf){printf("-1\n");}
	else{printf("%lld\n",ans);}
	return 0;
}