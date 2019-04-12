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
	string kata;
	cin>>kata;
	int dp[55],i,j;
	int pjg = kata.length();
	for(i=0;i<pjg;i++){
		dp[i] = 1;
		for(j=i-1;j>=0;j--){
			if(kata[j] < kata[i]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maks = *max_element(dp, dp+pjg);
	printf("%d\n",26-maks);
	return 0;
};