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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

ii pas[maxn];

bool cmp(ll a, ll b){
	return a > b;
}

int main(){
	freopen("icecream.in", "r", stdin);
	ll a[maxn];
	int tc,i,j,n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){scanf("%lld",&pas[i].first);}
		for(i=0;i<n;i++){scanf("%lld",&pas[i].second);}
		sort(pas, pas+n);
		int idx = k-1;
		ll bil = pas[idx].first;
		for(i=idx;i<n;i++){
			if(bil != pas[i].first){break;}
		}
		i--;

		int idxAkhir = i;
		int cnt = 0;
		for(i=idxAkhir;i>=0;i--){
			a[cnt++] = pas[i].second;
		}
		sort(a,a+cnt,cmp);
		ll sum = 0;
		for(i=0;i<k;i++){
			sum += a[i];
		}
		

		printf("%lld %lld\n",bil, sum);
	}
	return 0;
};