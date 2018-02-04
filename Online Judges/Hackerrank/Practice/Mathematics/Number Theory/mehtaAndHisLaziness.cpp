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

const int maxn = 1e6;
bool isprime[maxn+4];
int prime[78500];

ll numDiv(ll n){
	ll pf_idx = 0, pf = prime[pf_idx], ans = 1;
	while(pf*pf<=n){
		int power = 0;
		while(n%pf==0){n/=pf; power++;}
		ans*=(power+1);
		pf_idx++;
		pf = prime[pf_idx];
	}
	if(n!=1){ans*=2;}
	return ans;
}

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

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=2;i<=maxn;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}

	int square[1100];
	for(i=2;i<1100;i+=2){
		square[i] = i*i;
		if(square[i]>maxn){break;}
	}
	int idxMaks = i;
	while(tc--){
		scanf("%d",&n);
		ll numberOfDivisor = numDiv(n);
		numberOfDivisor--;
		// printf("numberOfDivisor: %lld\n",numberOfDivisor);
		ll cnt = 0;
		for(i=2;i<idxMaks;i+=2){
			// printf("n: %d square[%d]: %d\n",n,i,square[i]);
			if(n%square[i]==0){
				// printf("suare[%d]: %d\n",i,square[i]);
				if(square[i]==n){break;}
				cnt++;
			}
		}
		// printf("cnt: %lld\n",cnt);
		if(cnt==0){printf("0\n"); continue;}
		else{
			ll gcd = __gcd(cnt,numberOfDivisor);
			cnt/=gcd;
			numberOfDivisor/=gcd;
			printf("%lld/%lld\n",cnt,numberOfDivisor);
		}
	}
	return 0;
};