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

struct pas {
	int k, l, r, belakang, selisih;
};

bool cmp(pas a, pas b) {
	return a.l > b.l;
	// if(a.belakang >= b.belakang){
	// 	if(a.l <= b.l){
	// 		if(a.selisih <= b.selisih) {
	// 			return a.k > b.k;
	// 		}
	// 		return a.selisih > b.selisih;
	// 	}
	// 	return a.l > b.l;
	// }
	// return a.belakang < b.belakang;
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	pas a[200001];
	while(tc--){
		scanf("%d",&n);

		for(i=0;i<n;i++){
			scanf("%d %d %d",&a[i].k, &a[i].l, &a[i].r);
			if(a[i].l <= a[i].r){
				a[i].belakang = 1;
			}else{
				a[i].belakang = 0;
			}
			a[i].selisih = abs(a[i].l - a[i].r);
		}

		sort(a, a+n, cmp);
		ll ans = 0;
		for(i=0;i<n;i++){
			// printf("%d %d\n",a[i].l, a[i].r);
			if(a[i].k >= (i+1)){
				ans += a[i].l;
			}else{
				ans += a[i].r;
			}
			// printf("ans: %d\n",ans);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};