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

bool isprime[1130];
int prime[190],n;
int memo[188][1121][15];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i+i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int solve(int id, int bil, int sisa){
	if(sisa==0){
		if(bil==0){return 1;}
		else{return 0;}
	}
	if(id==n){return 0;}
	if(bil<prime[id]){return 0;}
	if(memo[id][bil][sisa]!=-1){return memo[id][bil][sisa];}
	return memo[id][bil][sisa] = solve(id+1,bil-prime[id],sisa-1) + solve(id+1,bil,sisa);
}

int main() {
	int a,b,i;
	memset(isprime,-1,sizeof isprime);
	sieve(1120);
	int cnt = 0;
	for(i=0;i<=1120;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	n = cnt;

	memset(memo,-1,sizeof memo);
	while(scanf("%d %d",&a,&b),(a||b)){
		int ans = solve(0,a,b);
		printf("%d\n",ans);
	}

	return 0;
}