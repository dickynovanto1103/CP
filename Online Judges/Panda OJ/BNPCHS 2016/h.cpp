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
	int i,j;
	ll n;
	int tc;
	int a[maxn];
	ll penambahan[maxn];
	ll sum[maxn];
	scanf("%d",&tc);
	penambahan[0] = 0;
	sum[0] = 0;
	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d: ",tt);
		scanf("%lld",&n);
		ll total = (n*(n+1LL))/2LL;
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		for(i=1;i<=n;i++){
			if(a[i]==1){penambahan[i]= penambahan[i-1] + i;}
			else{penambahan[i] = penambahan[i-1];}
			sum[i] = sum[i-1] + penambahan[i];
		}
		printf("%.3lf\n",(double)sum[n]/(double)total);
	}
	return 0;
};