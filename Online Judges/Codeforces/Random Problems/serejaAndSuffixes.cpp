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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j,m;
	int a[maxn];
	int dp[maxn];
	set<int> s;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dp[n] = 1;
	s.insert(a[n]);
	for(i=n-1;i>=1;i--){
		dp[i] = dp[i+1];
		if(s.count(a[i])==0){dp[i]++; s.insert(a[i]);}
	}
	for(i=0;i<m;i++){
		int idx;
		scanf("%d",&idx);
		printf("%d\n",dp[idx]);
	}
	return 0;
};