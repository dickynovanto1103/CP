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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi fac;
const int maxn = 2e6;
bool isprime[maxn + 6];
ll prime[150000];
void sieve(int n){
	ll i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

void factorize(ll bil){
	int i,j;
	ll pf_idx = 0, pf = prime[pf_idx];
	while((pf*pf)<=bil){
		if(bil%pf == 0){
			fac.pb(pf);
			// printf("yang dipush: %d\n",pf);
			while(bil%pf == 0){
				bil/=pf;
			}
		}
		pf = prime[++pf_idx];
	}
	if(bil != 1){
		fac.pb(bil);
		// printf("dipush: %d\n",bil);
	}
}

string kata;

bool isSame(int ukuran,int n){
	int i,j;
	string kataPertama = kata.substr(0,ukuran);
	// printf("kataPertama: "); cout<<kataPertama<<endl;
	// printf("ukuran: %d\n",ukuran);
	for(i=ukuran;i<n;i+=ukuran){
		string kataCocok = kata.substr(i,ukuran);
		// cout<<"kataCocok: "<<kataCocok<<endl;
		// printf("i: %d\n",i);
		if(kataCocok != kataPertama){return false;}
	}
	return true;
}

int main(){
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	int i,j;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	
	

	while(cin>>kata, kata!= "."){
		ll pjg = kata.length();
		if(pjg == 1){printf("1\n"); continue;}
		fac.pb(1);
		factorize(pjg);
		ll ans = 1;
		// printf("ukuran fac: %d\n",(int)fac.size());
		for(i=0;i<fac.size();i++){
			ll ukuran = fac[i];
			// printf("ukuran: %d\n",ukuran);
			if(isSame(ukuran, pjg)){
				ans = max(ans, pjg/ukuran);
			}
		}
		printf("%lld\n",ans);
		fac.clear();
	}



	return 0;
};