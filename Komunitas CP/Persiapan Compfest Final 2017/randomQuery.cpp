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

const int maxn = 1e6 + 10;
ll a[maxn], last[maxn], sum[maxn];

int main(){
	ll n;
	int i;
	scanf("%lld",&n);
	memset(last,-1,sizeof last);
	ll ans = 0;
	sum[0] = 1;
	
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(i==0){
			ans=1;
			last[a[0]] = 0;
			continue;
		}
		if(last[a[i]]==-1){
			sum[i] = sum[i-1] + i + 1;
		}else{
			sum[i] = sum[i-1] + i - last[a[i]];
		}
		ans+=sum[i];
		last[a[i]] = i;
		// printf("last[%d]: %d\n",a[i],last[a[i]]);
		//  printf("sum[%d]: %lld ans jd: %lld\n",i,sum[i],ans);
	}
	ans = ans*2 - n; 
	printf("%.6lf\n", (double)ans/(double)(n*n));
	return 0;
};