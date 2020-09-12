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

ll duapangkat[200001];
ll pref[200002];
ll suff[200002];

int occ[200001];
const ll mod = 1e9 + 7;

ll modPow(ll a, ll b) {
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a * modPow(a, b-1) % mod;}
		else{
			ll temp = modPow(a, b/2);
			return temp*temp % mod;
		}
	}
}

int main(){
	int n,p[200001];
	int i,j;
	scanf("%d",&n);
	duapangkat[0] = 1;
	for(i=1;i<=n;i++){
		duapangkat[i] = 2LL * duapangkat[i-1];
		duapangkat[i] %= mod;
	}

	int maksNum = 0;

	for(i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		occ[a]++;
		maksNum = max(maksNum, a);
	}
	for(i=0;i<=maksNum+1;i++){
		suff[i] = 1;
		pref[i] = 1;
	}

	for(i=1;i<=maksNum;i++){
		pref[i] = pref[i-1] * (occ[i] + 1);
		// printf("pref[%d]: %lld\n",i, pref[i]);
		pref[i] %= (mod-1);
	}
	for(i=maksNum;i>=1;i--){
		suff[i] = suff[i+1] * (occ[i] + 1);
		// printf("suff[%d]: %lld\n",i, suff[i]);
		suff[i] %= (mod-1);
	}

	ll ans = 1;
	for(i=1;i<=maksNum;i++){
		ll pangkat1 = (occ[i]*(occ[i]+1))/2;
		pangkat1 %= (mod-1);
		ll pangkat2 = pref[i-1]*suff[i+1];
		pangkat2 %= (mod-1);
		ll kali = pangkat2 * pangkat1;	
		// printf("i: %d pangkat1: %lld pangkat2: %lld\n",i, pangkat1, pangkat2);
		kali %= (mod-1);
		ll jawab = modPow(i, kali);
		ans *= jawab;
		ans %= mod;
		// printf("ans jd: %lld\n",ans);
	}
	printf("%lld\n",ans);

	return 0;
};