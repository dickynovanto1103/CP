#include <bits/stdc++.h>

using namespace std;
#define inf 1e18
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,int> ii;
typedef vector<ii> vii;

const int maxn = 3e5 + 5;

ll suf[maxn];

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int a[maxn];
	
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		suf[i] = a[i];
	}
	ll pertama = 0;
	for(i=n-1;i>=1;i--){
		suf[i]+=suf[i+1];
		pertama = suf[i];
	}
	sort(suf + 2, suf + n + 1);
	ll ans = 0;
	for(i=n;i>=n-k+2;i--){
		// printf("suff[%d]: %lld\n",i,suf[i]);
		ans += suf[i];
	}
	ans += pertama;
	printf("%lld\n",ans);
	return 0;
};