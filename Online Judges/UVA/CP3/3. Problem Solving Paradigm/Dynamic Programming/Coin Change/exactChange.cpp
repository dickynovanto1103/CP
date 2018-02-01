#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,i,j, dp[20010],a[110],biaya,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&biaya);
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		dp[0] = 0;
		for(i=1;i<=20000;i++){dp[i] = inf;}
		for(i=0;i<n;i++){
			for(j=20000-a[i];j>=0;j--){
				if(dp[j]<inf){
					dp[j+a[i]] = min(dp[j+a[i]], dp[j] + 1);
				}
			}
		}
		//printf("biaya: %d\n",biaya);
		for(i=biaya;i<=20000;i++){
			if(dp[i]<inf){printf("%d %d\n",i,dp[i]); break;}
		}
	}
	return 0;
}