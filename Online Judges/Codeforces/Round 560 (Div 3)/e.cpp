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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

const ll mod = 998244353;

struct pasangan{
	ll tot;
	int idx;
};

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn],b[maxn];
	ll kon[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	sort(b,b+n,cmp);
	for(i=0;i<n;i++){
		kon[i] = (ll)(i+1)*((ll)n-i);
		// printf("kon[%d]: %lld\n",i,kon[i]);
	}
	ll tot[maxn];
	for(i=0;i<n;i++){
		tot[i] = kon[i]*(ll)a[i];
	}
	sort(tot, tot+n);
	ll ans = 0;
	for(i=0;i<n;i++){
		tot[i] %= mod;
		ans += tot[i]*(ll)b[i];
		ans %= mod;
	}
	printf("%lld\n",ans);

	return 0;
};