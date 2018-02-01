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

int isprime[100010], prime[5200];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i+i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

vi primefactor(int n){
	vi factor;
	//printf("n: %d\n",n);
	if(n<0){n*=-1; factor.pb(-1);}
	ll idx = 0, pf = prime[idx];
	while(pf*pf<=n){
		while(n%pf==0){factor.pb(pf); n/=pf;}
		pf = prime[++idx];	
	}
	
	if(n!=1){factor.pb(n);}
	return factor;
	
}

int main() {
	int n,i;
	memset(isprime,true,sizeof isprime);
	sieve(50000);
	int cnt = 0;
	for(i=0;i<=50000;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	//printf("cnt: %d\n",cnt);
	while(scanf("%d",&n),n){
		//printf("n: %lld\n",n);
		vi ans = primefactor(n);
		int ukuran = ans.size();
		//printf("ukuran: %d\n",ukuran);
		printf("%d = ",n);
		for(i=0;i<ukuran;i++){
			if(i){printf(" x ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}