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

const int maxn = 1e5;
bool isprime[maxn + 3];
int prime[maxn];

void sieve(int n) {
	isprime[0] = isprime[1] = false;
	for(int i=2;i*i<=n;i++){
		if(isprime[i]){
			for(int j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main(){
	ll n;
	int i,j;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=1;i<maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	scanf("%lld",&n);
	vi primeFactors;
	int pangkat[100001];
	ll ans = 1;
	for(i=0;i<cnt;i++){
		ll p = prime[i];
		if(p > n){break;}
		if(p * p <= n) {
			printf("B %lld\n",p);
			fflush(stdout);
			int bil;
			scanf("%d",&bil);

			printf("B %lld\n",p);
			fflush(stdout);
			scanf("%d",&bil);
			if(bil == 1){
				primeFactors.pb(p);
				ans *= p;
				pangkat[p] = 1;
			}
		} else {
			printf("B %lld\n",p);
			fflush(stdout);
			int bil;
			scanf("%d",&bil);
			if(bil > 1){ //berarti ada dia dan jawabannya yg lebih besar dari current p
				primeFactors.pb(p);
				ans *= p;
				pangkat[p] = 1;
			}
		}
	}
	if(primeFactors.size() == 0){
		printf("A 1\n");
		fflush(stdout);
		int bil;
		scanf("%d",&bil);
		if(bil == 1){
			printf("C 1\n");
			fflush(stdout);
		}else{
			printf("C 1\n");
			fflush(stdout);
		}
	}else{
		for(i=0;i<primeFactors.size();i++){
			ll p = primeFactors[i];
			ll temp = ans;
			for(j=0;j<20;j++) {
				pangkat[p]++;
				temp *= p;
				if(temp > n) {
					temp /= p;
					pangkat[p]--;
				}else{
					printf("B %lld\n", temp);
					fflush(stdout);
					int bil;
					scanf("%d",&bil);
					assert(bil <= 1);
					if(bil == 1){
						ans = temp;
					}else{ //bil == 0
						pangkat[p]--;
						temp /= p;
						break;
					}
				}
			}
		}
		printf("C %lld\n",ans);
		fflush(stdout);
	}
	
	return 0;
};