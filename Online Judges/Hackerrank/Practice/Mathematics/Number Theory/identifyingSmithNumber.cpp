#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[46500];
int prime[4810];
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

ll jumlahBilanganTiapDigit(ll n){
	ll sum = 0;
	while(n>0){sum+=(n%10); n/=10;}
	return sum;
}

int factor(ll n){
	ll idx = 0, pf = prime[idx], sum = 0;
	ll awal = n;
	while(pf*pf<=n){
		while(n%pf==0){n/=pf; sum+=jumlahBilanganTiapDigit(pf);}
		pf = prime[++idx];
	}
	if(n!=1){
		if(n==awal){return -inf;}
		else{sum+=jumlahBilanganTiapDigit(n);}
	}
	return sum;
}

int main() {
	ll n,m = 46500;
	int i;
	memset(isprime,true,sizeof isprime);
	sieve(m);
	int cnt = 0;
	for(i=0;i<=m;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	//printf("cnt: %d\n",cnt);
	scanf("%lld",&n);
	ll ans1 = jumlahBilanganTiapDigit(n);
	ll ans2 = factor(n);
	//printf("ans1: %lld ans2: %lld\n",ans1,ans2);
	if(ans1==ans2){
		printf("1\n");
	}else{
		printf("0\n");
	}
	return 0;
}