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

ll memo[1002][1002][5];
int a[5];
int val[] = {0,1,2,5,10};

ll solve(int sisa, int freq, int idx){
	
}

int main(){
	int tc,n,i,j,k;
	scanf("%d",&tc);
	//memset
	n = 1000;
	for(i=0;i<=n;i++){
		for(j=0;j<=1000;j++){
			for(k=0;k<=4;k++){
				memo[i][j][k] = -1;
			}
		}
	}
	while(tc--){
		scanf("%d",&n);
		for(i=1;i<=4;i++){scanf("%d",&a[i]);}
		a[0] = 0;
		int maks = a[1];
		for(i=2;i<=4;i++){
			maks = max(maks,a[i]);
		}
		ll ans = solve(n,a[4],4);
		printf("%lld\n",ans);
	}
	return 0;
};