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

const int maxn = 2e5 + 5;
ll a[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);

	ll sum = 0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		sum += a[i];
	}

	sort(a, a + n);
	// printf("arr: ");
	// for(int i=0;i<n;i++){
	// 	printf("%lld ", a[i]);
	// }
	// printf("\n");
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		ll def, att;
		scanf("%lld %lld",&def,&att);
		int idxLb = lower_bound(a, a+n, def) - a;
		int awal = idxLb;
		if(idxLb == n) {
			idxLb--;
		}

		// printf("idxLb skrg: %d\n", idxLb);

		ll tambah1 = max(def - a[idxLb], 0LL);
		ll tambah2 = (sum - a[idxLb] >= att ? 0 : att - (sum - a[idxLb]));
		ll ans1 = tambah2 + tambah1;

		// printf("ans1: %lld\n", ans1);

		if(awal == n || awal == 0){
			printf("%lld\n",ans1);
			continue;
		}

		tambah1 = max(def - a[idxLb - 1], 0LL);
		tambah2 = (sum - a[idxLb - 1] >= att ? 0 : att - (sum - a[idxLb - 1]));
		ll ans2 = tambah2 + tambah1;

		// printf("ans2: %lld\n", ans2);

		printf("%lld\n", min(ans1, ans2));

	}
	
	return 0;
};