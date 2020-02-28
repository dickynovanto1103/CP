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

int dp[65][1000001];

void process(int n, const vi& a){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = inf;
		}
	}
	for(int i=0;i<a.size();i++){
		printf("%d\n",a[i]);
		dp[i][a[i]] = 1;
	}
	for(int i=0;i<a.size();i++){
		dp[i][0] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a.size();j++){
			if(a[j] > i){break;}
			if(j){
				dp[j][i] = min(dp[j-1][i], dp[j][i-a[j]] + 1);	
			}else{
				dp[j][i] = min(dp[j][i], dp[j][i-a[j]] + 1);
			}
			
		}
	}
}

void trackback(int n, const vi& a){
	int minim = inf;
	int idx;
	for(int i=0;i<a.size();i++){
		printf("dp[%d][%d]: %d\n",i,n,dp[i][n]);
		if(dp[i][n] < minim){
			minim = dp[i][n];

			idx = i;
		}
	}
	printf("%d\n",minim);
	vi ans;
	while(n){
		for(int i=0;i<a.size();i++){
			if(n >= a[i]){
				if(dp[i][n-a[i]] == minim-1){
					ans.pb(a[i]);
					n -= a[i];
					minim--;
				}
			}
		}
	}
	for(int a: ans){
		printf("%d ",a);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	vi a;
	a.pb(1);
	int pangkat[] = {1,10,100,1000,10000,100000};
	for(i=1;i<=5;i++){
		int tambah = pangkat[i];
		for(j=0;j<(1<<i);j++){
			int ans = 0;
			for(int k=0;k<i;k++){
				if(j & (1<<k)){
					ans += pangkat[k];
				}
			}
			a.pb(ans + tambah);
		}
	}
	a.pb(1000000);
	printf("ukuran: %d\n",(int)a.size());

	process(n, a);

	trackback(n,a);
	return 0;
};