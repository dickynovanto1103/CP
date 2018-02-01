#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

uint64 memo[62][62];

uint64 trib(int n, uint64 back){
	uint64 sum = 1;
	int i;
	if(n<=1){return 1;}
	if(memo[n][back]!=-1){return memo[n][back];}
	for(i=1;i<=back;i++){
		sum += trib(n-i,back);
	}
	return memo[n][back] = sum;
}

int main() {
	memset(memo,-1,sizeof memo);
	int a;
	uint64 b;
	int test = 1;
	while(scanf("%d %llu",&a,&b),(a<=60)){
		//printf("%d %llu\n",a,b);
		uint64 ans = trib(a,b);
		printf("Case %d: %llu\n",test++,ans);
	}
	
	return 0;
}