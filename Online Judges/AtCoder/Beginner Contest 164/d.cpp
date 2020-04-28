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

ll modPow(ll a, ll b, ll mod) {
	if(b == 0){
		return 1;
	}else{
		if(b % 2 == 1){
			return a * modPow(a,b-1, mod) % mod;
		}else{
			ll temp = modPow(a,b/2, mod);
			return temp*temp%mod;
		}
	}
}

int main(){
	// ll modVal = 1000000007;
	// ll ans = modPow(10, modVal-2, modVal);
	// printf("ans %d\n",ans);
	// printf("akhir %d\n",ans*10 % modVal);
	string s;
	cin>>s;
	int i,j,n;
	n = s.size();
	int mod = 2019;
	ll bil = 0;
	int cnt[2019];
	memset(cnt, 0, sizeof cnt);
	int resMod[200001];

	for(i=0;i<n;i++){
		bil *= 10;
		bil += s[i]	- '0';
		bil %= mod;
		resMod[i] = bil;

	}
	// printf("resMod[n-1]: %d\n",resMod[n-1]);
	cnt[resMod[n-1]]++;
	int temp = 0;
	for(i=1;i<n;i++){
		temp *= 10;
		temp += s[i-1] - '0';
		temp %= mod;
		bil = temp;
		bil %= mod;
		bil *= modPow(10, n-i, mod);
		bil %= mod;
		ll ans = resMod[n-1] - bil;
		if(ans < 0){ans+=mod;}
		cnt[ans]++;

		// printf("i: %d ans: %lld\n",i, ans);
	}
	cnt[0]++; //for the end

	ll ans = 0;
	for(i=0;i<2019;i++){
		ans += ((ll)cnt[i]*(cnt[i]-1))/2LL;
	}
	printf("%lld\n",ans);
	// for(i=1;i<=9;i++){
	// 	int bil = i;
	// 	for(j=1;j<=200000;j++){
	// 		bil *= 10;
	// 		bil %= mod;
	// 		modRes[i][j] = bil;
	// 		cnt[i][bil]++;
	// 	}
	// }

	// adj.assign(11, vi());

	// for(i=1;i<=9;i++){
	// 	for(j=0;j<2019;j++){
	// 		if(cnt[i][j]){
	// 			adj[i].pb(j);
	// 		}
	// 	}
	// }

	// ll ans = 0;
	// int modString[2019];
	// memset(modString, 0, sizeof modString);
	// int bil = 0;
	// for(i=0;i<n;i++){
	// 	bil *= 10;
	// 	bil += s[i] - '0';
	// 	bil %= mod;

	// 	modString[bil]++;
	// }

	// ans += modString[0];
	// modString[0] = 0;

	// for(i=0;i<n-1;i++){
	// 	//assume num = s[i] - '0'
	// 	//try to reduce the whole sequence with num * 1e1, num * 1e2, ... , num 1e
	// }
	
	return 0;
};