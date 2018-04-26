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

int main(){
	int n,i,j;
	scanf("%d",&n);
	int dp[30];
	dp[1] = 3;
	for(i=2;i<=20;i++){
		dp[i] = dp[i-1] + 2;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf(" ");
		}
		printf("*\n");
	}
	for(i=0;i<dp[n];i++){
		printf("*");
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf(" ");
		}
		printf("*\n");
	}
	return 0;
};