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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		vi v(n);
		for(int i=0;i<n;i++) {
			scanf("%d",&v[i]);
		}
		
		set<int> s;
		set<int>::iterator it;
		for(int i=0;i<n;i++){
			s.insert(v[i]);
		}

		vi un;
		for(it = s.begin(); it!= s.end();it++) {
			un.pb(*it);
		}

		assert(un.size() > 0);

		if(un.size() == 1) {
			printf("0\n");
			continue;
		}else if(un.size() == 2) {
			ll ans = 2 * (un[un.size() - 1] - un[0]);
			printf("%lld\n", ans);
		}else{
			ll ans = un[un.size() - 1] - un[0];
			// printf("sini\n");
			ans += max(un[1] - un[0], un[un.size() - 1] - un[un.size() - 2]);
			ll ans1 = ans;
			
			//cari jawaban kedua
			int sz = un.size();
			ll ans2 = 2 * (un[1] - un[0]) + (un[2] - un[1]);
			ll ans3 = 2 * (un[sz-1] - un[sz-2]) + (un[sz-2] - un[sz-3]);

			//cari jawaban terakhir
			ll ans4 = 0;
			//cari maks jarak in between
			for(int i=1;i<sz-1;i++){
				ll ansAmbilPertama = (un[sz-1] - un[i]) + (un[i+1] - un[i]);
				ll ansAmbilKedua = (un[i+1] - un[0]) + (un[i+1] - un[i]);
				ans4 = max(ans4, max(ansAmbilPertama, ansAmbilKedua));
			}
			printf("%lld\n", max(ans1, max(ans2, max(ans3, ans4))));
		}

		
	}
	
	return 0;
};