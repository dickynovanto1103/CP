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

const int maxn = 1e5;
bool isprime[maxn+2];

int prime[10000];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int factorize(ll n){
	ll idx = 0, pf = prime[idx];
	int ans = 0;
	while(pf*pf<=n){
		while(n%pf == 0){
			ans++;
			n/=pf;
		}
		pf = prime[++idx];
	}
	if(n!=1){
		ans++;
	}
	return ans;
}

int main(){
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(int i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	int n;
	scanf("%d",&n);
	printf("%d\n",factorize(n));
	return 0;
};