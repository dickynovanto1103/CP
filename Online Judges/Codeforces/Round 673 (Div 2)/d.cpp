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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

ll a[10002];

void cetak(int n){
	printf("cetak\n");
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	printf("\n");
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		ll sum = 0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum += a[i];
		}
		printf("sum: %lld n: %lld\n",sum, n);
		if(sum % n != 0){
			printf("-1\n");
			continue;
		}
		ll expected = sum / n;
		//coba kosongin dulu 
		viii ans;
		for(i=2;i<=n;i++){
			ll bagi = a[i] / i;
			ll sisa = a[i] % i;

			ans.pb(iii(ii(i, 1), bagi));
			a[i] = sisa;
			a[1] += bagi*i;
			debug cetak(n);
		}
		bool valid = true;
		for(i=2;i<=n;i++){
			if(a[i] == expected){
				continue;
			}else if(a[i] < expected) {
				//tambahin dari satu
				ll selisih = expected - a[i];
				ans.pb(iii(ii(1, i), selisih));
				a[i] += selisih;
				a[1] -= selisih;
				if(a[1] < 0){
					valid = false;
					break;
				}
				debug cetak(n);
			}else{
				ll nearestDivisible = i;
				ll selisih = nearestDivisible - a[i];
				ans.pb(iii(ii(1, i), selisih));
				a[1] -= selisih;
				a[i] += selisih;
				if(a[1] < 0){
					valid = false;
					break;
				}
				ans.pb(iii(ii(i, 1), 1));
				a[1] += nearestDivisible;
				a[i] = 0;
				ans.pb(iii(ii(1, i), expected));
				//tambahin dari 1 sampe 
				a[1] -= expected;
				a[i] = expected;
				if(a[1] < 0){
					valid = false;
					break;
				}
				debug cetak(n);
			}
		}
		if(!valid){printf("-1\n"); continue;}
		for(i=1;i<=n;i++){
			assert(a[i] == expected);
		}
		assert((int)ans.size() <= 3*n);
		printf("%d\n",(int)ans.size());
		for(i=0;i<ans.size();i++){
			printf("%d %d %d\n",ans[i].first.first, ans[i].first.second, ans[i].second);
		}
	}
	
	return 0;
};