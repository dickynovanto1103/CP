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

int cntPrime[500];
vi primeList;

vi factorize(int bil) {
	vi ans;
	for(int i=0;i<primeList.size();i++){
		int p = primeList[i];
		while(bil % p == 0){
			ans.pb(p);
			bil /= p;
		}
	}
	if(bil != 1){
		ans.pb(bil);
	}
	return ans;
}

int main(){
	int tmpCntPrime[500];

	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		memset(cntPrime, 0, sizeof cntPrime);
		memset(tmpCntPrime, 0, sizeof tmpCntPrime);
		primeList.clear();

		int n;
		scanf("%d",&n);
		vi listNum;
		ll sumAllNum = 0;
		for(int i=0;i<n;i++){
			int p, m;
			scanf("%d %d",&p,&m);
			cntPrime[p] = m;
			sumAllNum += ((ll)p * m);
			primeList.pb(p);
		}

		ll ans = 0;
		for(i=2;i<=sumAllNum;i++){
			ll tempSum = sumAllNum;
			vi factors = factorize(i);
			
			for(int i=0;i<primeList.size();i++){
				int p = primeList[i];
				tmpCntPrime[p] = cntPrime[p];
			}

			bool valid = true;
			ll kali = 1;
			for(int f: factors) {
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