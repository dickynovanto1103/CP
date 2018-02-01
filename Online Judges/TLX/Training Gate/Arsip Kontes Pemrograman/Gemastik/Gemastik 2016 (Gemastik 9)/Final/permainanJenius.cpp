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

const int maxn = 31650;
bool isprime[maxn];
int prime[3410];

void sieve(ll n){
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

int calculatePrimeFactor(ll n){
	ll idx = 0, pf = prime[idx], cnt = 0;
	while(pf*pf<=n){
		while(n%pf==0){n/=pf; cnt++;}
		pf = prime[++idx];
	}
	if(n!=1){
		cnt++;
		
	}
	return cnt;
}

int main(){
	int tc,i,j,n;
	int a[10010];
	int grun[1000];
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int hasilXor = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			hasilXor^=calculatePrimeFactor(a[i]);
		}
		if(hasilXor==0){printf("YA\n");}
		else{printf("TIDAK\n");}
	}
	
	return 0;
};