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

const ll maxn = 1000000;
bool isprime[maxn+10];
ll prime[78500];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

ll numPF(ll n){
	ll pf_idx = 0, pf = prime[pf_idx], ans = 0;
	while(pf*pf<=n){
		while(n%pf==0){n/=pf; ans++;}
		pf = prime[++pf_idx];
	}
	if(n!=1){ans++;}
	return ans;
}


int main(){
	int tc,i,j,n;
	ll a[110];
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	/*for(i=1;i<=12;i++){
		printf("i: %d: %lld\n",i,numPF(i));
	}*/
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int tot = 0;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			ll jawab = numPF(a[i]);
			//printf("jumlahFaktor dari %lld: %lld\n",a[i],jawab);
			tot^=jawab;
		}
		if(tot==0){printf("2\n");}
		else{printf("1\n");}

	}
	return 0;
};