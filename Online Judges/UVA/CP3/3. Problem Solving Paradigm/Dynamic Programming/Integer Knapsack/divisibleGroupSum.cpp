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

ll a[210],d;
int memo[201][21][11],n;

int solve(int id, ll bil, int sisa){
	if(sisa==0){
		if(bil==0){return 1;}
		else{return 0;}
	}
	if(id==n){return 0;}
	if(memo[id][bil][sisa]!=-1){return memo[id][bil][sisa];}
	ll temp = (bil+a[id])%d;
	//if(temp<0){temp = (d-((-(bil+a[id]))%d))%d;}
	if(temp<0){temp = ((d-(-((bil+a[id])%d)))%d);}
	return memo[id][bil][sisa] = solve(id+1,temp%d,sisa-1) + solve(id+1,bil,sisa);
}

int main() {
	int i,m,q,test=1;
	//printf("%d\n",-101%8);
	while(scanf("%d %d",&n,&q),(n||q)){
		printf("SET %d:\n",test++);
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		
		for(i=1;i<=q;i++){
			memset(memo,-1,sizeof memo);
			scanf("%lld %d",&d,&m);
			int ans = solve(0,0,m);
			printf("QUERY %d: %d\n",i,ans);
		}
	}
	return 0;
}