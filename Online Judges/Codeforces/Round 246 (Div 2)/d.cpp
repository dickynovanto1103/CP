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

string s;

const int maxn = 1e5 + 5;
int p[maxn];
int cnt[maxn];
int Z[maxn];

void computePrefix(int n) {
	for(int i=1;i<n;i++){
		int j = p[i-1];
		while(j > 0 && s[j] != s[i]) {
			j = p[j-1];
		}
		if(s[j] == s[i]) {
			j++;
		}
		p[i] = j;
		if(i < n-1)
			cnt[p[i]]++;
	}
}

ll hash1[maxn];
const ll pr = 29, mod = 1e9 + 7;

void computeHash(int n){
	ll pow = 1;
	for(int i=0;i<n;i++){
		hash1[i] = s[i]*pow;
		hash1[i] %= mod;
		if(i){
			hash1[i] += hash1[i-1];
			hash1[i]%=mod;
		}
		pow *= pr;
		pow %= mod;
	}
}

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll getHash(int awal, int akhir, int patokan){
	ll result = (hash1[akhir] - (awal == 0 ? 0 : hash1[awal-1]) + mod) % mod;
	int selisih = patokan - awal;
	result *= modPow(pr, selisih);
	result %= mod;
	return result;
}

void computeZ() {
	int L = 0, R = 0;
	int n = s.length();
	for(int i=0;i<n;i++){
		if(i > R){
			L = R = i;
			while(R < n && s[R] == s[R-L]) ++R;
			Z[i] = R-L; --R;
		}else{
			int k = i-L;
			if(Z[k] < R-i+1) Z[i] = Z[k];
			else{
				L=i;
				while(R < n && s[R] == s[R-L]) ++R;
				Z[i] = R-L; --R;
			}
		}
	}
}

int jawab[maxn];

void solve(int n) {
	for(int i=0;i<n;i++){
		if(Z[i]){
			int akhir = i + Z[i];
			int batas = Z[i];
			if(akhir == n){
				batas--;
			}
			jawab[1]++; jawab[batas+1]--;
			// jawab[i]++; jawab[akhir+1]--;
		}
	}
}

int main(){
	cin>>s;
	int n = s.length(), i,j;
	computePrefix(n);
	computeZ();

	solve(n);
	for(i=1;i<n;i++){
		jawab[i] += jawab[i-1];
		// printf("jawab[%d]: %d\n",i,jawab[i]);
	}

	vii ans;
	computeHash(n);
	for(i=1;i<n;i++){
		ll hash1 = getHash(0,i-1, n-i);
		ll hash2 = getHash(n-i, n-1, n-i);
		// printf("%d %d dan %d %d\n",0,i-1,n-i,n-1);
		// printf("hash1: %lld hash2: %lld\n",hash1,hash2);
		if(hash1 == hash2){
			ans.pb(ii(i, 2 + jawab[i]));
		}
	}
	ans.pb(ii(n, 1));
	int ukuran = ans.size();
	printf("%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		printf("%d %d\n",ans[i].first, ans[i].second);
	}
	return 0;
};