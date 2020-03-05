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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[501];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int uang;
	scanf("%d",&uang);

	int dp[50001];
	for(i=0;i<=50000;i++){dp[i] = inf;}

	dp[0] = 0;
	for(i=1;i<=uang;i++){
		for(j=0;j<n;j++){
			if((i - a[j]) >= 0) {
				dp[i] = min(dp[i], dp[i-a[j]] + 1);
			}
		}
	}

	if(dp[uang] == inf){
		dp[uang] = -1;
	}

	printf("%d\n",dp[uang]);

	return 0;
};