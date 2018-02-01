#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[1000100];
int prime[80000];

vi primefactor(ll n){
	vi factors;
	ll idx = 0, pf = prime[idx];
	//printf("n awal: %lld\n",n);
	while(pf*pf<=n){
		//printf("pf: %d\n",pf);
		while(n%pf==0){n/=pf; factors.push_back(pf); }
		pf = prime[++idx];
	}
	if(n!=1){factors.push_back(n);}
	return factors;
}

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

int main() {
	int i,j;
	
	memset(isprime,true,sizeof isprime);
	sieve(1000000);
	int cnt = 0;
	for(i=0;i<=1000000;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}

	//printf("cnt: %d\n",cnt);
	ll n;
	//scanf("%lld",&n);
	vi r = primefactor(2147483647);
	
	printf("r:\n");
	int ukuran= r.size();
	for(i=0;i<ukuran;i++){printf(" %d",r[i]);}
	printf("\n");
	vi s = primefactor(136117223861LL);
	printf("s:\n");
	ukuran= s.size();
	for(i=0;i<ukuran;i++){printf(" %d",s[i]);}
	printf("\n");
	vi t = primefactor(142391208960LL);
	printf("t:\n");
	ukuran= t.size();
	for(i=0;i<ukuran;i++){printf(" %d",t[i]);}
	scanf("%lld",&n);
	t.clear();
	t = primefactor(n);
	printf("\n");
	
	printf("t:");
ukuran= t.size();
	for(i=0;i<ukuran;i++){printf(" %d",t[i]);}
	printf("\n");
	return 0;
}