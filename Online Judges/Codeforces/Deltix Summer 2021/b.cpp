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

ll hitung(vi v, int startPos, int n) {
	ll ans = 0;
	int idx = 0;
	for(int i=startPos;i<n;i+=2) {
		if(idx >= v.size()){
			assert(false);
		}
		ans += abs(i - v[idx++]);
	}
	return ans;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[100010];
	while(tc--){
		scanf("%d",&n);
		vi posGenap, posGanjil;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] % 2 == 0) {
				posGenap.pb(i);
			}else{
				posGanjil.pb(i);
			}
		}
		if(n == 1){
			printf("0\n");
			continue;
		}
		if(n % 2 == 1) {
			int n1 = posGenap.size(), n2 = posGanjil.size();
			if(abs(n1-n2) != 1){
				printf("-1\n");
				continue;
			}
		}else{
			if(posGanjil.size() != posGenap.size()){
				printf("-1\n");
				continue;
			}
		}

		//hitung
		ll ans = inf * (ll)inf;
		if(n % 2 == 1){
			if(posGenap.size() > posGanjil.size()) {
				ans = min(ans, hitung(posGenap, 0, n));
				ans = min(ans, hitung(posGanjil, 1, n));
			}else{
				ans = min(ans, hitung(posGanjil, 0, n));
				ans = min(ans, hitung(posGenap, 1, n));
			}
		}else {
			ans = min(ans, hitung(posGanjil, 0, n));
			ans = min(ans, hitung(posGanjil, 1, n));
			ans = min(ans, hitung(posGenap, 0, n));
			ans = min(ans, hitung(posGenap, 1, n));
		}

		printf("%lld\n", ans);
	}
	
	return 0;
};