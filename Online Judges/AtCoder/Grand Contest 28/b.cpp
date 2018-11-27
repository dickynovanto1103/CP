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
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll fact[maxn];
ll inv[maxn];

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	fact[0] = 1;
	for(i=1;i<=n;i++){
		fact[i] = fact[i-1]*(ll)i;
		fact[i] %= mod;
	}
	//hitung inverse
	for(i=1;i<=n;i++){
		inv[i] = modPow(i,mod-2);
		// printf("nilai inv[%d]: %lld\n",i,inv[i]);
	}
	for(i=2;i<=n;i++){
		inv[i] += inv[i-1];
		inv[i] %= mod;
	}
	//hitung expected number masing"index
	ll ans = 0;
	for(i=0;i<n;i++){
		//hitung yang ke kiri
		// printf("i: %d\n",i);
		int jarakKeKiri = i + 1;
		int jarakKeKanan = n-i;
		ll expected = inv[jarakKeKiri] + inv[jarakKeKanan] - 1LL;
		if(expected < 0){expected += mod;}
		expected %= mod;
		// printf("inv[%d]: %lld inv[%d]: %lld expected: %lld\n",jarakKeKiri,inv[jarakKeKiri],jarakKeKanan,inv[jarakKeKanan], expected);
		expected *= fact[n];
		expected %= mod;
		ans += (expected*(ll)a[i]);
		// printf("ans awal jadi: %lld\n",ans);
		ans %= mod;
		// printf("ans jd: %lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
};