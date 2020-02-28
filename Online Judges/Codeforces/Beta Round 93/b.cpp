#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6 + 5;

string T; //input string
int n;

int hash1[maxn];
int p[maxn];
ll inv1[maxn];
const ll p1 = 29;

const ll mod = 1e9 + 7;

int cnt[maxn];

void computePrefix() {
	memset(p, 0, sizeof p);
	for(int i=1;i<n;i++){
		int j = p[i-1];
		while(j > 0 && T[j] != T[i]) {
			j = p[j-1];
		}
		if(T[j] == T[i]){
			j++;
		}
		p[i] = j;
		if(i < n-1){
			cnt[p[i]]++;
		}
		// printf("p[%d]: %d\n",i,p[i]);
	}
}

void hitung(int* hash, ll p) {
	ll pow = 1;
	for(int i=0;i<n;i++){
		ll temp = (ll)T[i]*pow%mod;
		hash[i] = temp;
		if(i) {
			hash[i] += hash[i-1];
			if(hash[i] >= mod){
				hash[i] -= mod;
			}
			// hash[i] %= mod;
		}
		pow *= p; pow %= mod;
	}
}

void hitungPow(ll* inv, ll p) {
	ll pow = 1;
	for(int i=0;i<maxn;i++){
		inv[i] = pow;
		pow *= p;
		pow %= mod;
	}
}

void computeHash() {
	hitung(hash1, p1);
	// hitung(hash2, p2);
}

void computeModInverse() {
	hitungPow(inv1, p1);
	// hitungPow(inv2, p2);
}

int getHash(int awal, int akhir, int patokan) {
	ll val1 = (hash1[akhir] - (awal == 0 ? 0 : hash1[awal-1]));
	if(val1 < 0){val1 += mod;}
	int selisih = patokan - awal;
	assert(selisih >= 0);
	val1 *= inv1[selisih];
	val1 %= mod;
	return val1;
}

int main() {
	// FastSlowInput
	computeModInverse();
	while(cin>>T){
		memset(cnt, 0, sizeof cnt);
		n = T.length();
		computeHash();
		computePrefix();
		int ans = 0;
		string jawab;

		for(int i=1;i<n-1;i++){
			int hashAwal = getHash(0, i-1, n-i);
			int hashAkhir = getHash(n-i, n-1, n-i);
			if(hashAkhir == hashAwal) {
				if(cnt[i]){
					ans = i;
				}
			}
			
		}
		if(ans){
			for(int i=0;i<ans;i++){
				printf("%c",T[i]);
			}
			printf("\n");
		}else{
			printf("Just a legend\n");
		}
	}
	
	return 0;
}