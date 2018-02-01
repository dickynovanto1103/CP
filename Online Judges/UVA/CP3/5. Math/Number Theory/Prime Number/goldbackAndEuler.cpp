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


const int maxn = 10010;
bool isprime[maxn+10];
int prime[maxn+10];
int cnt;

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

bool apakahPrima(int n){
	if(n<=maxn){return isprime[n];}
	for(int i=0;i<cnt;i++){
		if(n%prime[i]==0){return false;}
	}
	return true;
}

int main(){
	int n,i,j;
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}

	//printf("cnt: %d\n",cnt);
	while(scanf("%lld",&n)!=EOF){
		int a = -1,b = -1;
		ll tengah = (ll)n/2;
		int idx = lower_bound(prime,prime+cnt,tengah)-prime;
		printf("tengah: %d idx: %d\n",tengah,idx);
		if(prime[idx]>tengah){idx--;}
		printf("idx jd: %d\n",idx);
		printf("prime[%d]: %d\n",idx,prime[idx]);
		for(i=idx;i>=0;i--){
			//if(prime[i]*prime[i] > n){break;}
			int bil1 = prime[i];
			int bil2 = n-prime[i];
			if(bil1==bil2){continue;}
			if(apakahPrima(bil2)){a = bil1; b = bil2; break;}
		}
		if(a==-1 && b==-1){printf("%lld is not the sum of two primes!\n",n);}
		else{printf("%lld is the sum of %d and %d.\n",n,a,b);}
	}
	return 0;
};