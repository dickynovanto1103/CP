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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll cntPrime[500];
vi primeList;

vi factorize(ll bil) {
	vi ans;
	for(int i=0;i<primeList.size();i++){
		ll p = primeList[i];
		// printf("p: %lld\n", p);
		while(bil % p == 0){
			ans.pb(p);
			bil /= p;
			// printf("push to ans: %lld\n", p);
		}
	}
	if(bil != 1){
		ans.pb(bil);
		// printf("final push bil: %lld\n", bil);
	}
	return ans;
}

int main(){
	ll tmpCntPrime[500];

	int tc,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		
		memset(cntPrime, 0, sizeof cntPrime);
		memset(tmpCntPrime, 0, sizeof tmpCntPrime);
		primeList.clear();

		int n;
		scanf("%d",&n);

		ll sumAllNum = 0;
		for(int i=0;i<n;i++){
			int p;
			ll m;
			scanf("%d %lld",&p,&m);
			cntPrime[p] = m;
			sumAllNum += ((ll)p * m);
			primeList.pb(p);
		}
		// printf("sumAllNum: %lld\n", sumAllNum);

		ll ans = 0;
		for(ll i=max(sumAllNum - (59 * 499), 2LL);i<=sumAllNum;i++){
			// printf("i: %lld\n",i);
			ll tempSum = sumAllNum;
			vi factors = factorize(i);
			
			for(int j=0;j<primeList.size();j++){
				int p = primeList[j];
				tmpCntPrime[p] = cntPrime[p];
			}

			bool valid = true;
			ll kali = 1;
			for(ll f: factors) {
				// printf("factor: %lld\n", f);
				if(f >= 500 || tmpCntPrime[f] == 0) {
					valid = false;
					break;
				}
				tmpCntPrime[f]--;
				tempSum -= f;
				kali *= f;
			}
			if(valid && kali == tempSum) {
				ans = kali;
			}
		}

		printf("%lld\n",ans);
	}
	
	return 0;
};