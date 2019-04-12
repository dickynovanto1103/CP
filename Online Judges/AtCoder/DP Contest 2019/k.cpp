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

const int maxn = 1e2 + 2;

set<int> s;

int findGrun() {
	for(int i=0;;i++){
		if(!s.count(i)){return i;}
	}
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int a[maxn];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	// grundy number method

	// int grun[100010];
	// grun[0] = 0;
	// for(i=1;i<=k;i++){
	// 	s.clear();
	// 	for(j=0;j<n;j++){
	// 		if(i-a[j] >= 0){
	// 			s.insert(grun[i-a[j]]);
	// 			// printf("diinsert: %d\n",i-a[j]);
	// 		}
	// 	}
	// 	grun[i] = findGrun();
	// 	// printf("grun[%d]: %d\n\n",i,grun[i]);
	// }
	// if(grun[k] == 0){printf("Second\n");}
	// else{printf("First\n");}

	// dp bottom up approach
	// dp[k] = condition that at k stone, if 1 then player 1 win, 0 otherwise
	// approach from i pick condition from back
	// int dp[100010];
	
	// dp[0] = 0;
	// for(i=1;i<=k;i++){
	// 	dp[i] = 0;
	// 	for(j=0;j<n;j++){
	// 		if(a[j] <= i){
	// 			if(dp[i - a[j]] == 0){
	// 				dp[i] = 1;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	// printf("%s\n",(dp[k]? "First": "Second"));

	int dp[100010];
	memset(dp, 0, sizeof dp);
	for(i=0;i<=k;i++){
		if(dp[i] == 0){
			for(j=0;j<n;j++){
				if((a[j] + i) <= k){
					dp[a[j] + i] = 1 - dp[i];
				}
			}	
		}
		
	}
	printf("%s\n",(dp[k]? "First": "Second"));
	return 0;
};