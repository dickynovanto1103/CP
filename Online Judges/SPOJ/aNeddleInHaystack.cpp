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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;
const ll p = 31;

ll hashFunction(const string& kata) {
	int i,j;
	ll ans = 0;
	ll pangkat = 1;
	for(i=0;i<kata.length();i++){
		char kar = kata[i];
		ans += ((ll)(kar - 'a' + 1)*pangkat);
		ans %= mod;
		pangkat *= p;
		pangkat %= mod;
	}
	return ans;
}

vi listHash;

void constructHash(const string& kata) {
	ll pangkat = 1;
	int pjgHay = kata.length();
	// printf("pjgHay: %d\n",pjgHay);
	// cout<<"kata "<<kata<<endl;
	for(int i=0;i<pjgHay;i++){
		char kar = kata[i];
		ll ans = (ll)(kar - 'a' + 1)*pangkat;
		ans %= mod;
		listHash.pb(ans);
		// printf("ans: %lld\n",ans);
		if(listHash.size() > 1){
			listHash[i] += listHash[i-1];
			listHash[i] %= mod;
			// printf("listHash[%d]: %lld\n",i,listHash[i]);
		}
		pangkat *= p;
		pangkat %= mod;
	}
}

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a,b-1) % mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll modInverse(ll n){
	return modPow(n, mod-2);
}

int main(){
	FastSlowInput

	int n,i,j;
	int tc = 0;

	while(cin>>n) {
		// printf("n: %d\n",n);
		if(tc == 1){cout<<endl;}
		string needle, haystack;
		cin>>needle>>haystack;
		int pjg = needle.size();
		ll nilaiHash = hashFunction(needle);

		int pjgHay = haystack.length();
		constructHash(haystack);

		ll pangkat = 1;
		for(i=0;i<pjgHay;i++){
			int akhir = i + pjg - 1;
			if(akhir >= pjgHay){break;}
			ll nilai = listHash[akhir];
			if(i > 0){

				nilai -= listHash[i-1];
			}
			if(nilai < 0){

				nilai += mod;
			}

			//bagi
			// printf("halo\n");
			nilai *= modInverse(pangkat);
			// printf("nilai: %lld\n",nilai);
			nilai %= mod;

			if(nilai == nilaiHash){cout<<i<<endl;}
			pangkat *= p;
			pangkat %= mod;
		}



		tc = 1;
		listHash.clear();
	}
	return 0;
};