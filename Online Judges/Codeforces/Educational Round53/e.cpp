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

vi digit;
const ll mod = 998244353;
int k;
ll dp[20][1<<10][2];
ll cnt[20][1<<10][2];

ll pangkat10[20];
ll bitCnt[1<<10];

void parse(ll n){
	digit.clear();
	while(n > 0){
		ll bil = n%10LL;
		n /= 10LL;
		digit.pb(bil);
	}
	reverse(digit.begin(), digit.end());
}

ll solveCnt(int idx, int mask, int isPrefixSama){
	if(idx == digit.size()){return 1;}
	ll& ans = cnt[idx][mask][isPrefixSama];
	if(ans != -1){return ans;}
	
	int batas = digit[idx];
	if(!isPrefixSama){batas = 9;}
	int awal = (idx == 0) ? 1: 0;

	ans = 0;
	for(int i=awal;i<=batas;i++){
		int maskBaru = mask | (1<<i);
		if(bitCnt[maskBaru] > k){continue;}
		if(i == batas){
			ans += solveCnt(idx+1, maskBaru, isPrefixSama);
		}else{
			ans += solveCnt(idx+1, maskBaru, 0);
		}
		ans %= mod;
	}
	return ans;
}

ll solve(int idx, int mask, int isPrefixSama){
	if(idx == digit.size()){return 0;}

	ll& ans = dp[idx][mask][isPrefixSama];
	if(ans != -1){return ans;}

	int batas = digit[idx];
	if(!isPrefixSama){batas = 9;}
	int awal = (idx == 0) ? 1: 0;

	ans = 0;
	for(int i=awal;i<=batas;i++){
		int maskBaru = mask | (1<<i);
		// printf("i: %d\n",i);
		if(bitCnt[maskBaru] > k){continue;}
		if(i == batas){
			ll banyakValid = solveCnt(idx+1, maskBaru, isPrefixSama);
			
			ll tambah = ((i * pangkat10[digit.size() - idx - 1])%mod * (banyakValid%mod))%mod;
			
			ans += tambah;
			ans %= mod;
			ans += solve(idx+1, maskBaru, isPrefixSama);
		}else{
			ll banyakValid = solveCnt(idx+1, maskBaru, 0);
			
			ll tambah = ((i * pangkat10[digit.size() - idx - 1])%mod * (banyakValid%mod))%mod;
			
			ans += tambah;
			ans %= mod;
			ans += solve(idx+1, maskBaru, 0);
		}
		ans %= mod;
	}
	return ans;
}

ll selesaikan(ll bil){
	parse(bil);
	int pjg = digit.size();
	ll ans = 0;
	ll angka = 0;
	for(int i=1;i<pjg;i++){
		angka *= 10LL;
		angka += 9LL;
		
		parse(angka);
		memset(dp, -1, sizeof dp); memset(cnt, -1, sizeof cnt);
		ll jawab = solve(0,0,1);
		
		ans += jawab;
		ans %= mod;
	}
	memset(dp, -1, sizeof dp); memset(cnt, -1, sizeof cnt);
	parse(bil);
	ll jawab = solve(0,0,1);
	ans += jawab;
	ans %= mod;
	return ans;
}

int main(){
	ll l,r;
	pangkat10[0] = 1LL;
	for(int i=1;i<20;i++){
		pangkat10[i] = 10LL*pangkat10[i-1];
		pangkat10[i]%=mod;
	}
	for(int i=0;i<(1<<10);i++){
		bitCnt[i] = __builtin_popcount(i);
	}
	scanf("%lld %lld %d",&l,&r,&k);
	ll ans = selesaikan(r) - selesaikan(l-1);
	if(ans < 0){ans += mod;}
	printf("%lld\n",ans);
	return 0;
};