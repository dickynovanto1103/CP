#include <bits/stdc++.h>

using namespace std;
#define inf 1e16
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct person{
	int h,p;
	void read() {
		scanf("%d %d",&h,&p);
	}
};

bool cmp(person a, person b){
	return a.h + a.p < b.h + b.p;
}

const int maxn = 5e3 + 3;

ll dp[maxn]; //dp[i][j] menyatakan banyaknya minimal sum of p sampe idx i dengan banyaknya peserta yg ikut adalah j
ll temp[maxn];

void minim(ll &a, ll b){
	a = min(a, b);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	vector<person> a(n+1);
	for(i=1;i<=n;i++){
		a[i].read();
	}
	sort(a.begin(), a.end(), cmp);

	for(i=1;i<=n;i++){
		// printf("i: %d\n",i);
		if(i > 1){
			for(j=0;j<i;j++){
				dp[j] = temp[j];
				// printf("dp[%d]: %lld\n",j,dp[j]);
			}
			dp[j] = inf;
		}else{
			temp[0] = 0;
			for(j=1;j<=i;j++){
				dp[j] = inf;
				temp[j] = 0;
			}
		}
		
		int h = a[i].h, p = a[i].p;
		// printf("h: %d p: %d\n",h,p);
		for(j=1;j<=i;j++){
			if(h >= temp[j-1]){
				minim(dp[j], temp[j-1] + p);
				// printf("masuk sini dp[%d][%d]: %lld\n",i,j+1, dp[i][j+1]);
			}
		}

		for(j=0;j<=i;j++){
			temp[j] = dp[j];
			dp[j] = 0;
		}
	}
	int ans = 0;
	
	for(j=0;j<=n;j++){
		// printf("dp[%d]: %lld\n",j,dp[j]);
		if(temp[j] != inf){
			ans = max(ans, j);
		}
	}
	
	printf("%d\n",ans);
	return 0;
};